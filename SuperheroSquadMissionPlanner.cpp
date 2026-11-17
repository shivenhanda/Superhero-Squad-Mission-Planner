#include<iostream>
#include<string>
using namespace std;

struct Hero {
    string name;
    int powerLevel;
};
void displayHeroes(Hero heroes[]){
	cout<<"Available Heroes:"<<endl;	
	for(int i=0;i<5;i++){
		cout<<i+1<<". "<<heroes[i].name<<" "<<"Power-"<<heroes[i].powerLevel<<" Level"<<endl;
	}
}
void startMission(Hero heroes[]);
int main(){
	cout<<"=====Superhero Squad Mission Planner====="<<endl;
	Hero heroes[5] = {
    {"Hero 1", 10},
    {"Hero 2", 20},
    {"Hero 3", 30},
    {"Hero 4", 40},
    {"Hero 5", 50}
	};
	int choice=0;
	while(true){
		cout<<endl;
		cout<<"1. Enter the Available Heroes"<<endl;
		cout<<"2. Select Heroes and Start Mission"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				{
					displayHeroes(heroes);
					break;
				}
			case 2:
				{
					startMission(heroes);
					break;
				}
			case 3:{
				cout<<"Exiting program..."<<endl;
				break;
			}
			default:
				cout<<"Enter Number 1 to 3"<<endl;
			}
			if(choice==3) break;
		}
		return 0;
}
void startMission(Hero heroes[]){
	int villain=100;
	int num=0;
	cout << "Enter the number of heroes you want to select:" << endl;
	cin>>num;
	while(num>5 || num<1){
		cout<<"Enter Number of heroes 1 to 5:"<<endl;
		cin>>num;
	}
	int sum=0;
	int n=0;
	bool select[5]={};
	for(int i=0;i<num;i++){
		cout<<"Enter Hero Number "<<i+1<<": "<<endl;
		cin>>n;
		if(n>5 || n<1){
			cout << "Invalid hero number! Try again."<< endl;
			i--;
			continue;
		}
		else if(select[n-1]){
			cout << "Hero already selected! Choose another hero." << endl;
			i--;
			continue;
		}
		else{
			select[n-1]=true;
			sum+=heroes[n-1].powerLevel;
		}
	}
	if(sum>=villain){
		cout<<"Mission Successful"<<endl;
	}
	else{
		cout<<"Mission Failed"<<endl;
	}
}
