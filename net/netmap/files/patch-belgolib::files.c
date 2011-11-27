--- belgolib/files.c.orig	2010-01-06 08:00:52.000000000 +0900
+++ belgolib/files.c	2011-11-23 22:22:36.000000000 +0900
@@ -17,7 +17,7 @@
 
 Infile::Infile() : ifstream() { }
 
-Infile::Infile(const string& file_name, int mode, bool fatal)
+Infile::Infile(const string& file_name, ios::openmode mode, bool fatal)
     : ifstream(file_name.c_str(), (std::_Ios_Openmode)mode)
 {
 
@@ -39,7 +39,7 @@
 }
 
 
-int Infile::Open(const string & file_name, int mode, bool fatal)
+int Infile::Open(const string & file_name, ios::openmode mode, bool fatal)
 {
     
     if(cdb>d_list)
