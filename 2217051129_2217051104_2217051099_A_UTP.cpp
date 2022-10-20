//Kelompok 13 Kelas A
//David Nico Natanael Rumahorbo, NPM : 2217051129
//Muhaamd Fakhri Wilova, NPM : 2217051104
//Muhammad Setiawan Wibisono, NPM : 2217051099

#include <iostream> //standar input output
#include <string.h> //untuk mengoperasikan strcpy
#include <time.h> //untuk mengkonversi waktu
using namespace std;

void tiketkonser (char nama[50])
{
	struct tm *Sys_T;
	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);//untuk mendapatkan waktu lokal komputer
	int i,pembayaran,beli_tiket,jumlah_tiket[100],harga[100],nominal[100],pilih,kembalian,total_harga=0,kode[5];
	char kls[100][30];
	cout<<"\n\tMasukan Banyak Pembelian Tiket : ";
	cin>>beli_tiket;
	cout<<"\n\t--------------------------------------------------";
	cout<<"\n";
	
	for(i=1;i<=beli_tiket;i++){
		cout<<"\n\tPembelian Tiket ke "<<i;
		kode:
		cout<<"\n\tKode Kelas : ";
		cin>>kode[i];
		
		if(kode[i]==1){
			strcpy(kls[i],"VVIP");
			harga[i]=3000000;
		}
		else if(kode[i]==2){
			strcpy(kls[i],"VIP");
			harga[i]=2500000;
		}
		else if(kode[i]==3){
			strcpy(kls[i],"EKSEKUTIF");
			harga[i]=2000000;
		}
		else if(kode[i]==4){
			strcpy(kls[i],"BISNIS");
			harga[i]=1500000;
		}
		else if(kode[i]==5){
			strcpy(kls[i],"EKONOMI");
			harga[i]=1000000;
		}
		else{
			cout<<"\n\t\t\t\tKODE KELAS SALAH !!\n";
			goto kode;
		}
		cout<<" \tMasukan Jumlah Tiket : ";
		cin>>jumlah_tiket[i];
		cout<<"\n\t--------------------------------------------------\n";
	}
	
	for(i=1;i<=beli_tiket;i++){
		nominal[i]=jumlah_tiket[i]*harga[i];//mencari total harga masing masing kelas
		total_harga=total_harga+nominal[i];//mecari total harga keseluruhan
	}
	
	system ("cls");
	
	cout<<"\t\t =========== Pembayaran =========== "<<endl;
	cout<<"	Total Harga Keseluruhan\t  : Rp. "<<total_harga<<"\n";
	pil1:
	cout<<"	Masukan Jumlah Pembayaran : Rp. ";
	cin>>pembayaran;
	kembalian = pembayaran-total_harga;
	
	if(pembayaran >= total_harga){
		system("cls");
		goto data;
	}
	else{
		cout<<"\n	UANG ANDA KURANG !!\n";
		cout<<"\n";
		goto pil1;
	}
	
	data:
		
		system ("cls");
	
	cout<<"\t===================================================================\n";
	cout<<"\t================[ DATA PEMBAYARAN TIKET KONSER ]===================\n";
	cout<<"\t===================================================================\n";
	cout<<"\n";
	cout<<"\tNama Pemesan\t\t: "<<nama;
	cout<<"\n\tDate			: "<< Sys_T->tm_mday<<" - "<< Sys_T->tm_mon+1<<" - "<< 1900+Sys_T->tm_year;
	cout<<"\n\tTime			: "<< Sys_T->tm_hour<<" : "<< Sys_T->tm_min<<" : "<< Sys_T->tm_sec;
	cout<<"\n\t================================================================\n";
	cout<<"\n\t  No |  Kelas\t|  Harga\t|   Jumlah\t|  Subtotal\t";
	cout<<"\n\t================================================================\n";
	
	for(i=1;i<=beli_tiket;i++){
		printf("\n\t %d. | %s\t| Rp.%d \t| %d\t     | Rp.%d\t\n",i,kls[i],harga[i],jumlah_tiket[i],nominal[i]);
	}
	
	cout<<"\n\t===================================================================\n";
	cout<<"\n\t  Total Harga\t\t\t\t     | Rp. "<<total_harga<<"\n";
	cout<<"\n\t  Pembayaran\t\t\t\t     | Rp. "<<pembayaran<<"\n";
	cout<<"\n\t  Kembalian\t\t\t\t     | Rp. "<<kembalian<<"\n";
	cout<<"\n\t===================================================================\n";
}

int main()
{
	char nama[50];
	int pilih;
	awal:
	
	system ("cls");
	
	cout<<"\n";
	cout<<"\t>>>>>>>> [ DAFTAR TIKET KONSER ARDHITUKAM ] <<<<<<<< \n";
	cout<<"\t====================================================\n";
	cout<<"\t|   Kode Kelas   |    Kelas     |     Harga        |\n";
	cout<<"\t|----------------|--------------|------------------|\n";
	cout<<"\t|       1        |  VVIP        | Rp. 3.000.000    |\n";
	cout<<"\t|       2        |  VIP         | Rp. 2.500.000    |\n";
	cout<<"\t|       3        |  EKSEKUTIF   | Rp. 2.000.000    |\n";
	cout<<"\t|       4        |  BISNIS      | Rp. 1.500.000    |\n";
	cout<<"\t|       5        |  EKONOMI     | Rp. 1.500.000    |\n";
	cout<<"\t====================================================\n";
	cout<<"\n";
	cout<<"\n\tMasukan Nama depan Pembeli : ";
	cin>>nama;
	
	
	tiketkonser (nama);
	
	pil2:
	cout<<"\n";
	cout<<"  Tekan [1] untuk lanjut membeli, dan [0] untuk selesai\n => ";
	cin>>pilih;
	cout<<"\n";
	
	if(pilih==0){
		goto akhir;
	}
	else if(pilih==1){
		goto awal;
	}
	else{
		cout<<"KODE INVALID !";
		goto pil2;
	}
	akhir:
	system ("cls");
	
	cout<<" TERIMA KASIH SUDAH MEMBELI TIKET ^_^ \n";		
}
