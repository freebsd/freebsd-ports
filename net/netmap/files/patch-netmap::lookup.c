--- netmap/lookup.c.orig	Sun Dec 15 14:54:26 2002
+++ netmap/lookup.c	Sun Dec 15 14:54:26 2002
@@ -1,6 +1,8 @@
 #include <strstream>
 #include <iostream>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netdb.h> 	//hostent def
 
 //from belgolib
@@ -83,7 +85,7 @@
     if(verbose_lvl)
 	cout << indent(2) << "Reading " << fname << endl;
     
-    Infile cfile(fname, ios::bin | ios::in);
+    Infile cfile(fname, ios::binary | ios::in);
 
     while(cfile && !cfile.eof()) {
 	HostRec hr;
@@ -229,7 +231,7 @@
 
 void LookUp::read_failedip(const string& fname) 
 {
-    Infile cfile(fname, ios::bin | ios::in);
+    Infile cfile(fname, ios::binary | ios::in);
 
     while(cfile && !cfile.eof()) {
 	string ip;
