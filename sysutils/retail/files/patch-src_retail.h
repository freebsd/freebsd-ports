--- src/retail.h.orig	2003-03-18 17:48:46 UTC
+++ src/retail.h
@@ -19,16 +19,16 @@
  */
 
 /* global variables	*/
-short int retval;	/* what value do we return at the end of all this	*/
-short int debug;	/* do we go into debug mode?  (developer test only	*/
-FILE *in_file;		/* the files we'll be reading for input			*/
-FILE *in_stat;		/* the file we're using to store our place in in_file	*/
-char *st_filename;	/* the var we store the name of the offset file 	*/
-	
-char **files;		/* an array of all the file's we'll be opening		*/
-char *suffix;		/* suffix of the file we open to store stats in		*/
-char *prefix;		/* prefix directory for where we put stats files	*/
+extern short int retval;	/* what value do we return at the end of all this	*/
+extern short int debug;	/* do we go into debug mode?  (developer test only		*/
+extern FILE *in_file;		/* the files we'll be reading for input			*/
+extern FILE *in_stat;		/* the file we're using to store our place in in_file	*/
+extern char *st_filename;	/* the var we store the name of the offset file 	*/
 
+extern char **files;		/* an array of all the file's we'll be opening		*/
+extern char *suffix;		/* suffix of the file we open to store stats in		*/
+extern char *prefix;		/* prefix directory for where we put stats files	*/
+
 /* structure for our info on the file	*/
 typedef struct {
 	long int ipos;	/* last position as an int		*/
@@ -36,7 +36,7 @@ typedef struct {
 	char *last_line; /* last known line in the file		*/
 } FILE_STAT;
 
-FILE_STAT f;
+extern FILE_STAT f;
 
 /* our local functions */
 int proc_args(int argc, char **argv);
