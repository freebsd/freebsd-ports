--- Meshio.cpp.orig	Thu Apr  5 10:00:13 2001
+++ Meshio.cpp	Fri Dec 19 00:07:55 2003
@@ -15,9 +15,9 @@
 
 #include "Meshio.h"
 const char *OFortranUnFormattedFile::unkown("unkown file name");
-void (*MeshIstreamErrorHandler)(ios & ) =0;
+void (*MeshIstreamErrorHandler)(std::ios & ) =0;
 ///////////////////////////////////////////////////////////
- void WriteStr(ostream & out,char * str)
+ void WriteStr(std::ostream & out,char * str)
 { 
   int i=0;
   char c;
@@ -125,14 +125,14 @@
   if (CurrentFile)
     cerr << " In  file " <<  CurrentFile ;
   cerr << ", Erreur Lecture "  << s << 
-    ", good="  << (s & ios::goodbit) <<
-    ", bad=" << (s & ios::badbit) <<
-    ", fail=" << (s & ios::failbit) <<
-    ", eof=" << (s & ios::eofbit) << " Line " << LineNumber <<
+    ", good="  << (s & std::ios::goodbit) <<
+    ", bad=" << (s & std::ios::badbit) <<
+    ", fail=" << (s & std::ios::failbit) <<
+    ", eof=" << (s & std::ios::eofbit) << " Line " << LineNumber <<
     endl;
   if(!in.eof()) 
     {
-      in.clear(ios::goodbit);
+      in.clear(std::ios::goodbit);
       int i=0;
       char c;
       cerr << " the next character :" ;
@@ -143,7 +143,7 @@
   if (MeshIstreamErrorHandler)
     MeshIstreamErrorHandler(in);
   else 
-    in.clear(ios::failbit);
+    in.clear(std::ios::failbit);
 }
 int  MeshIstream::IsString(char* s)
 { 
@@ -201,7 +201,7 @@
 	break;
     }
   *b=0;
-  in.clear(ios::goodbit);
+  in.clear(std::ios::goodbit);
   //  cout << " l = " << b-buf << " " ;
   char * r = new char [b-buf+1];
   strcpy(r,buf);
