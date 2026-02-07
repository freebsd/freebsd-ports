--- utils.h.orig	Mon Oct 13 13:14:12 2003
+++ utils.h	Mon Oct 13 13:15:00 2003
@@ -50,19 +50,19 @@
 
 /* Error - print like fprintf(stderr, ...) and die. Progname included at
 	   beginning of message, newline at end. */
-extern void Error();
+extern void Error(char *, ...);
 /* Warning - like error, without dying */
-extern void Warning();
+extern void Warning(char *, ...);
 
 extern char *mylib_malloc();   
 extern char *mylib_realloc();
 extern char *mylib_scopy();
 extern char *mylib_srcopy();
-extern char *cat();
+extern char *cat(char *, ...);
 extern char *getstr();
 extern FILE *efopen();
 extern void efclose();
-extern void dfprintf();
+extern void dfprintf(int, FILE *, char *, ...);
 
 extern char *progname; /* application's name. Used by Error, Warning. */
 extern int d; /* debug level */
