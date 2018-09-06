#include<iostream>
#include<string>
#include "p1.h"
using namespace std;
//extern void p1_srand(int);
//extern int p1_rand();
//check if you win or lose. Returning 2 means you win. Returning 1 means you lose. Returning 0 means game should go on.
int checkGame(string dash_word_display, int score){
	if(score==10){
		return 1;
	}
	int dash_num=0;
	for(int i=0;i!=dash_word_display.size();i++){
		if(dash_word_display[i]=='_'){
			dash_num++;
		}
	}
	if(dash_num==0){
		return 2;
	}
	return 0;
}
//make the string for displaying letters and dashes
string makeDash(int word_num){
	string theword=words[word_num];
	string dashes;
	for(int i=0;i!=theword.size();i++){
		dashes=dashes+theword[i];
		dashes=dashes+" ";
	}
	return dashes;
}
//update the list of letters have been used
string updateUsedLetter(string letterused, char inputletter){
	int count=0;
	char space=' ';
	if(letterused.size()==0){
	letterused.insert(0,1,inputletter);	
	letterused.insert(1,1,space); 
	}	
	for(int i=0;i!=letterused.size();i++){
		if(inputletter==letterused[i]){
			count++;
			break;
		}
	 if(inputletter<letterused[i]){
			letterused.insert(i,1,inputletter);
			letterused.insert(i+1,1,space);
			count++;
			break;
		}
	}
	if(count==0){
		letterused=letterused+inputletter;
		letterused=letterused+' ';
	}
	
	return letterused;
}
//start the word guess game, input and output, make judgements.
int guessWord(int word_num){
	string dash_word,dash_word_display;
	dash_word=makeDash(word_num);
	dash_word_display=dash_word;
	for(int i=0;i!=dash_word_display.size();i++){
		if(dash_word_display[i]!=' '){
			dash_word_display[i]='_';
		}
	}
	string letterused;
	char inputletter;
	int score=0;
	while(1){
		cout<<"Score:"<<score<<endl;
		cout<<dash_word_display<<endl;
		cout<<"Already proposed character: "<<endl<<letterused<<endl;
		cout<<"Please enter a letter (a-z): ";
		cin>>inputletter;
		if(!((inputletter>='a')&&(inputletter<='z'))){
			continue;
		}
		int counter=0;
		int repeat_num=0;
		for(int i=0;i!=letterused.size();i++){
			if(inputletter==letterused[i]){
			repeat_num=1;
			}
		}
		if(repeat_num==1){
			continue;
		}
		for(int i=0;i!=dash_word.size();i++){
			if(inputletter==dash_word[i]){
				dash_word_display[i]=inputletter;
				counter++;
			}
		}
		if(counter==0){
			score++;
		}
		letterused=updateUsedLetter(letterused, inputletter);
		int result;
		result=checkGame(dash_word_display, score);
		if(result==1){
			cout<<"The word was: "<<words[word_num]<<endl<<"You lost!"<<endl;
			break;
		}
		else if(result==2){
			cout<<"The word was: "<<words[word_num]<<endl<<"You won!"<<endl;
			break;
		}
	}
	return 0; 
}

int main(){
	int seed,word_num;
	cout<<"Please input the seed:";
	cin>>seed;
	p1_srand(seed);
	word_num=p1_rand()%49+1;
	guessWord(word_num);
	
	return 0;
	
	
}
