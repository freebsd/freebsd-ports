--- Meshio.h.orig	Wed Mar 29 13:52:55 2000
+++ Meshio.h	Thu Dec 18 23:50:19 2003
@@ -14,8 +14,8 @@
 // ORIG-DATE:     Dec 97
 
 #include <stdio.h>
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <assert.h>
 #include <string.h>
 #include <stdlib.h>
@@ -25,14 +25,17 @@
 #if defined(__hpux) || defined(__SUNPRO_CC) 
 #define IOS_OPENMODE int
 #else
-#define IOS_OPENMODE ios::openmode
+#define IOS_OPENMODE std::ios::openmode
 #endif
 
+using std::cerr;
+using std::cout;
+using std::endl;
 
-extern  void (*MeshIstreamErrorHandler)(ios & );
+extern  void (*MeshIstreamErrorHandler)(std::ios & );
 extern  int verbosity ;
 
-void WriteStr(ostream & out,char * str);
+void WriteStr(std::ostream & out,char * str);
 
 double * ReadbbFile(const char * file,long & nbsol,long & lsol,const int dim=2,const int typesol=2);
 double * ReadBBFile(const char * file,long & nbsol,long & lsol,int *& typesols,const int dim=2,const int typesol=2);
@@ -42,12 +45,12 @@
 
 class  MeshIstream {
 public:
-  istream  & in ;
+  std::istream  & in ;
   //  ifstream  fin;
   int LineNumber,LineError,opened;
   const char * CurrentFile;
 
-  istream & cm ()//  mange les blancs et les commentaire 
+  std::istream & cm ()//  mange les blancs et les commentaire 
   { 
     char c;
     int cmm=0;
@@ -73,7 +76,7 @@
   //  MeshIstream(istream & i): in(i),CurrentFile(0),LineNumber(1),LineError(0) {}
 
   MeshIstream(const char * file_name)
-    : in(*new ifstream(file_name)),CurrentFile(file_name), LineNumber(1),LineError(0) 
+    : in(*new std::ifstream(file_name)),CurrentFile(file_name), LineNumber(1),LineError(0) 
   {    if (!in) {cerr << " Error Opening file " << file_name,CurrentFile=0;ShowIoErr(1);}
   if(verbosity>4) cout << "    Openfile : " << file_name << endl;err();  }
 
@@ -100,12 +103,12 @@
 class IFortranUnFormattedFile {
 //  template<class T> friend IFortranUnFormattedFile & operator>>(IFortranUnFormattedFile &f,T & l);
   long i,l,n,j,nb_rec;
-  istream * f;
+  std::istream * f;
   int to_close;
   const char * file_name;
  public:
   IFortranUnFormattedFile(char *name)
-    : f(new ifstream(name)),i(0),l(0),n((long)-sizeof(long)),
+    : f(new std::ifstream(name)),i(0),l(0),n((long)-sizeof(long)),
       nb_rec(0),file_name(name), to_close(1)
     { if(!*f) Error(0);}
 
@@ -125,16 +128,16 @@
 class OFortranUnFormattedFile {
 //  template<class T> friend OFortranUnFormattedFile & operator<<(OFortranUnFormattedFile &f,const T & l);
   long i,l,n,j,nb_rec;
-  ostream * f;
+  std::ostream * f;
   const static char * unkown;
   int to_close;
   const char * file_name;
  public:
   
-  OFortranUnFormattedFile(const char *name,IOS_OPENMODE  mm=ios::trunc)
-    : f(new ofstream(name,mm)),i(0),l(0),n((long) -sizeof(long)),nb_rec(0),file_name(name), to_close(1)
+  OFortranUnFormattedFile(const char *name,IOS_OPENMODE  mm=std::ios::trunc)
+    : f(new std::ofstream(name,mm)),i(0),l(0),n((long) -sizeof(long)),nb_rec(0),file_name(name), to_close(1)
     { if(!*f) Error(0);}
-  OFortranUnFormattedFile(ostream &ff)
+  OFortranUnFormattedFile(std::ostream &ff)
     : f(&ff),i(0),l(0),n((long) -sizeof(long)),nb_rec(0),file_name(unkown), to_close(0)
     { if(!*f) Error(0);}
   
