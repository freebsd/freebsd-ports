--- belgolib/files.c.orig	Sun Dec 15 14:54:27 2002
+++ belgolib/files.c	Sun Dec 15 14:54:27 2002
@@ -1,6 +1,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <assert.h>
+#include <iostream>
 
 #include "files.h"
 #include "debug.h"
@@ -16,7 +17,7 @@
 
 Infile::Infile() : ifstream() { }
 
-Infile::Infile(const string& file_name, int mode, bool fatal)
+Infile::Infile(const string& file_name, ios::openmode mode, bool fatal)
     : ifstream(file_name.c_str(), mode)
 {
 
@@ -38,7 +39,7 @@
 }
 
 
-int Infile::Open(const string & file_name, int mode, bool fatal)
+int Infile::Open(const string & file_name, ios::openmode mode, bool fatal)
 {
     
     if(cdb>d_list)
