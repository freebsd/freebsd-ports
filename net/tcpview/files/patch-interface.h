--- interface.h.orig	1993-04-22 20:47:58 UTC
+++ interface.h
@@ -59,8 +59,8 @@ extern char *lookup_device();
 
 extern char *lookup_device();
 
-extern void error();
-extern void warning();
+extern void error(char *, ...);
+extern void warning(char *, ...);
 
 extern char *read_infile();
 extern char *copy_argv();
