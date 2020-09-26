--- src/getopt.c.orig	2003-03-18 18:24:14 UTC
+++ src/getopt.c
@@ -21,6 +21,10 @@
 /* Yee ole includes (I put this all in one file for my sanity) */
 #include "include.h"
 
+short int debug;	/* do we go into debug mode?  (developer test only	*/
+char *suffix;		/* suffix of the file we open to store stats in		*/
+char *prefix;		/* prefix directory for where we put stats files	*/
+
 /* our 'print usage to user' function */
 void proc_args_usage(char *myname) {
 	fprintf(stderr, "retail v %s\n", VERSION);
