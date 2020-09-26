--- src/open_files.c.orig	2003-03-18 17:48:22 UTC
+++ src/open_files.c
@@ -21,6 +21,10 @@
 /* Yee ole includes (I put this all in one file for my sanity) */
 #include "include.h"
 
+FILE *in_file;		/* the files we'll be reading for input			*/
+FILE *in_stat;		/* the file we're using to store our place in in_file	*/
+char *st_filename;	/* the var we store the name of the offset file 	*/
+
 int open_infile(char *fname) {
 	/* open our input file read only */
 	in_file = fopen(fname, "r");
