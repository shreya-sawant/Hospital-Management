#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class hospital
{
protected:
	char hos_name[50], town_name[50];
public:
	hospital()
	{
		strcpy_s(hos_name, 50, "CITY HOSPITAL");
		strcpy_s(town_name, 50, "MARGAO");
	}

	void gi()
	{
		cout << "____________________" << hos_name << "____________________" << endl;
		cout << "_______________________" << town_name << "________________________" << endl << endl;
	}
};


class doctor :public hospital
{
protected:
	char doc_name[50], designation[50];
public:
	void get()
	{
		cout << "Enter Doctor detailes: " << endl;
		cout << "Doctor name: ";
		cin >> doc_name;
		cout << "Doctor designation: ";
		cin >> designation;
	}
	void put()
	{
		cout << "Doctor details: " << endl;
		cout << "Doctor name: " << doc_name << endl;
		cout << "Doctor designation: " << designation << endl;
	}
};

class patients :public doctor
{
protected:
	int no_of_patients;
	char patients_name[500][200];
	int treatment_fees[500], no_of_days_stayed[500], room_no[500];
public:
	void get_pat();
	void put_pat(int i);
};

void patients::get_pat()
{
	get();
	cout << "enter no. of patients\n";
	cin >> no_of_patients;
	cout << "enter patient details\n";
	for (int i = 0; i < no_of_patients; i++)
	{
		cout << "patient " << i + 1 << endl << "patient name: ";
		cin >> patients_name[i];
		cout << "room no.: ";
		cin >> room_no[i];
		cout << "no. of days patient stayed: ";
		cin >> no_of_days_stayed[i];
		cout << "treatment fees: ";
		cin >> treatment_fees[i];
		cout << endl;
	}
}

void patients::put_pat(int i)
{
	if (i == 0)
	{
		put();
	}

	else
	{
		cout << "Details of patients " << i << ":\n";
		cout << "Patient name: " << patients_name[i - 1];
		cout << "\nroom no.: " << room_no[i - 1];
		cout << "\nno. of days patient stayed: " << no_of_days_stayed[i - 1];
		cout << "\ntreatment fees: " << treatment_fees[i - 1];
	}


}

class outpatients :public doctor
{
protected:
	int no_of_outpatients, token_no[500];
	char patients_name[500][200], prescribed_med[500][200], problem[500][200], sonography[500];
public:
	void getopt();
	void putopt(int i);
	int cal(int i);
};

void outpatients::getopt()
{

	cout << "\nenter no. of outpatients\n";
	cin >> no_of_outpatients;
	cout << "enter patient details";
	for (int i = 0; i < no_of_outpatients; i++)
	{
		cout << "\npatient " << i + 1 << endl << "patient name: ";
		cin >> patients_name[i];
		cout << "Prescribed Medicine(use underscores as spaces): ";
		cin >> prescribed_med[i];
		cout << "Token no.:";
		cin >> token_no[i];
		cout << "Problem:";
		cin >> problem[i];
		cout << "Sonography:";
		cout << " Enter your choice(y/n):";
		cin >> sonography[i];
		cout << endl;
	}
}

int outpatients::cal(int i)
{
	if (sonography[i - 1] == 'y')
	{
		return 450;
	}
	else
	{
		return 200;
	}
}
void outpatients::putopt(int i)
{
	cout << "Details of outpatient " << i << ":\n";
	cout << "Patient name: " << patients_name[i - 1];
	cout << "\nPrescribed Medicine: " << prescribed_med[i - 1];
	cout << "\nToken no.: " << token_no[i - 1];
	if (sonography[i - 1] == 'Y' || sonography[i - 1] == 'y')
	{
		cout << "\nSonography: done";
	}
	else
	{
		cout << "\nSonography: not done";
	}
	cout << "\nProblem: " << problem[i - 1];
	cout << "\ntotal fees: " << cal(i);
}

class fees :public patients
{
	int t;
public:
	void re(int a)
	{
		t = a;
	}
	int operator+(fees f)
	{
		return (t + f.t * 150);
	}
};

class display :virtual public fees, virtual public outpatients
{
public:

	void show(char k, int i)
	{
		if (k == 'p')
		{
			fees f1, f2;
			f1.re(treatment_fees[i - 1]);
			f2.re(no_of_days_stayed[i - 1]);
			put_pat(i);
			cout << "\ntotal fees: " << f1 + f2;
		}
		else if (k == 'o')
		{
			putopt(i);
		}
	}
};

int main()
{
	char opt;
	int choice, n;
	hospital h1;
	display d1, d2;
	h1.gi();
	cout << "ENTER DETAILS OF DOCTOR 1 AND HIS PATIENTS \n";
	d1.get_pat();
	d1.getopt();

	cout << endl;
	cout << "ENTER DETAILS OF DOCTOR 2 AND HIS PATIENTS \n";
	d2.get_pat();
	d2.getopt();


	while (1)
	{
		cout << "\n\nSEARCH DETAILS OF PATIENT OF\nCHOOSE\n1.DOCTOR 1\n2.DOCTOR 2\n";
		cout.width(5);
		cout << "'OR'\n3.EXIT\nEnter your choice ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl;
			d1.put_pat(0);
			cout << endl;
			cout << "enter 'p' or 'o' to search details of patient or outpatient respectively" << endl;
			cin >> opt;
			cout << "enter no. of patient/outpatient" << endl;
			cin >> n;
			cout << endl;
			d1.show(opt, n);
			break;
		case 2:
			cout << endl;
			d1.put_pat(0);
			cout << endl;
			cout << "enter 'p' or 'o' to search details of patient or outpatient respectively" << endl;
			cin >> opt;
			cout << "enter no. of patient/outpatient" << endl;
			cin >> n;
			cout << endl;
			d2.show(opt, n);
			break;
		case 3:
			exit(0);
			break;
		default:cout << "invalid" << endl;
		}
	}
	_getch();
	return 0;
}
