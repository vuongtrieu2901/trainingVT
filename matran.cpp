#include <iomanip>
#include <complex>
#include <iostream>
using namespace std;


struct MATRAN
	{
		private:
		int soHang=10,soCot=10;
		float **mt=new float*[soHang];
		public:
			MATRAN(int m, int n):soHang(m),soCot(n)
			{
			for(int i=0;i<this->soHang;i++)
				this->mt[i]=new float[this->soCot];
			}
		void thaotac(int tt);
		void inMaTran();
		void nhapMaTran();
		void chuyenVi();
		void congMaTran();
		void truMaTran();
		void nhanMT_So();
		void nhanMT_MT();
		
		~MATRAN()
		{
			for(int i=0;i<this->soHang;i++) delete[] this->mt[i];
			delete[] this->mt;
			this->soHang=0; this->det=0; this->soCot=0;
		}
};
void MATRAN::thaotac(int tt){
	if(tt==0)
		{
		cout<<"\n+ Danh sach thao tac:\n";
		cout<<"\tChuyen vi:\t1|";
		cout<<"\tCong ma tran:\t2|";
		cout<<"\tTru ma tran:\t3|";
		cout<<"\n\tMa tran x So:\t4|";
		cout<<"\tMa tran x Ma tran:\t5|";
		cout<<"\n\tKet thuc lam viec:\t0";
		cout<<"\n\n+ Chon thao tac: ";
		cin>>tt;
		cout<<endl;
		}
	switch(tt){
		case 1: chuyenVi(); break;
		case 2: congMaTran(); break;
		case 3: truMaTran(); break;
		case 4: nhanMT_So(); break;
		case 5: nhanMT_MT(); break;
		default: break; 
	}
}
void MATRAN::inMaTran(){
	for(int i=0;i<this->soHang;i++){
		cout<<"\n\t";
		for(int j=0;j<this->soCot;j++) cout<<setw(5)<<this->mt[i][j]<<" ";
	}
	cout<<endl;
}
void MATRAN::nhapMaTran(){
	for(int i=0;i<this->soHang;i++)
		for(int j=0;j<this->soCot;j++){
			cout<<"\tPhan tu ["<<i+1<<","<<j+1<<"] = ";
			cin>>this->mt[i][j];
		}
	cout<<"Ma tran vua nhap :";
	this->inMaTran();
}

void MATRAN::chuyenVi(){
	MATRAN cv(this->soCot,this->soHang);
	for(int i=0;i<cv.soHang;i++)
		for(int j=0;j<cv.soCot;j++)
			cv.mt[i][j]=this->mt[j][i];
	cout<<"Ma tran chuyen vi cua ma tran A la:";
	cv.inMaTran();
	thaotac(0);
}
void MATRAN::congMaTran(){
	MATRAN b(this->soHang,this->soCot);
	cout<<"Nhap ma tran B:\n";
	b.nhapMaTran();
	for(int i=0;i<b.soHang;i++)
		for(int j=0;j<b.soCot;j++){
			b.mt[i][j]+=this->mt[i][j];
		}
	cout<<"Tong cua 2 ma tran A va B la:";
	b.inMaTran();
	thaotac(0);
}

void MATRAN::truMaTran(){
	MATRAN b(this->soHang,this->soCot);
	cout<<"Nhap ma tran B:\n";
	b.nhapMaTran();
	for(int i=0;i<b.soHang;i++)
		for(int j=0;j<b.soCot;j++){
			b.mt[i][j]=this->mt[i][j]-b.mt[i][j];
		}
	cout<<"Hieu cua 2 ma tran A va B la:";
	b.inMaTran();
	thaotac(0);
}

void MATRAN::nhanMT_So(){
	float x=1;
	MATRAN b(this->soHang,this->soCot);
	cout<<"Nhap vao so x: ";
	cin>>x;
	for(int i=0;i<b.soHang;i++)
		for(int j=0;j<b.soCot;j++)
			b.mt[i][j]=x*this->mt[i][j];
	cout<<"Tich cua "<<x<<" voi ma tran A la:";
	b.inMaTran();
	thaotac(0);
}

void MATRAN::nhanMT_MT(){
	int cotB=10;
	cout<<"Nhap so cot cua ma tran B: ";
	cin>>cotB;
	MATRAN b(this->soCot,cotB);
	cout<<"\nNhap ma tran B:\n";
	b.nhapMaTran();
	MATRAN c(this->soHang,b.soCot);
	for(int i=0;i<c.soHang;i++)
		for(int j=0;j<c.soCot;j++){
			c.mt[i][j]=0;
			for(int k=0;k<this->soCot;k++)
				c.mt[i][j]+=this->mt[i][k]*b.mt[k][j];
		}
	cout<<"Tich cua ma tran A va ma tran B la:";
	c.inMaTran();
	thaotac(0);
}
int main(){
	int m,n;
	cout<<"Nhap so hang cua ma tran A: ";
	cin>>m;
	cout<<"Nhap so cot cua ma tran A: ";
	cin>>n;
	MATRAN a(m,n);
	cout<<"\nNhap ma tran A:\n";
	a.nhapMaTran();
	a.thaotac(0);
	return 0;
}


