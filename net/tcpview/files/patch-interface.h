--- interface.h.orig	Tue Oct 28 01:36:19 2003
+++ interface.h	Tue Oct 28 01:36:30 2003
@@ -59,8 +59,8 @@
 
 extern char *lookup_device();
 
-extern void error();
-extern void warning();
+extern void error(char *, ...);
+extern void warning(char *, ...);
 
 extern char *read_infile();
 extern char *copy_argv();
