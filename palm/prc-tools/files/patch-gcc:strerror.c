--- ../gcc-2.95.3/libiberty/strerror.c-	Mon May  5 11:38:25 2003
+++ ../gcc-2.95.3/libiberty/strerror.c	Mon May  5 11:38:48 2003
@@ -462,8 +462,6 @@
 
 #else
 
-extern int sys_nerr;
-extern char *sys_errlist[];
 
 #endif
 
