--- src/main.c.orig	2003-03-18 17:48:18 UTC
+++ src/main.c
@@ -21,6 +21,8 @@
 /* Yee ole includes (I put this all in one file for my sanity) */
 #include "include.h"
 
+short int retval;	/* what value do we return at the end of all this	*/
+char **files;		/* an array of all the file's we'll be opening		*/
 
 int main(int argc, char **argv) {
 	long int i;
