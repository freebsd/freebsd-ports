--- ../gdb-5.0/libiberty/strerror.c.orig	Mon May  3 07:28:54 1999
+++ ../gdb-5.0/libiberty/strerror.c	Mon May  5 14:27:09 2003
@@ -462,8 +462,6 @@
 
 #else
 
-extern int sys_nerr;
-extern char *sys_errlist[];
 
 #endif
 
