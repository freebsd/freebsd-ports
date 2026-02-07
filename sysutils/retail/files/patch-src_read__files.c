--- src/read_files.c.orig	2003-03-18 17:48:28 UTC
+++ src/read_files.c
@@ -21,6 +21,8 @@
 /* Yee ole includes (I put this all in one file for my sanity) */
 #include "include.h"
 
+FILE_STAT f;
+
 int read_infile_llcheck() {
 	long int i;
 	short int found = 0;
