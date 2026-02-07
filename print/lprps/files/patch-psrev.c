--- psrev.c.orig	1993-02-22 21:46:09.000000000 +0900
+++ psrev.c	2013-04-27 22:56:35.000000000 +0900
@@ -5,6 +5,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -14,9 +15,6 @@
 extern int errno;
 #endif
 
-char *malloc();
-char *realloc();
-
 char *xmalloc();
 char *xrealloc();
 char *prog;
@@ -24,8 +22,8 @@
 void sys_error(message, arg)
 char *message, *arg;
 {
-  extern char *sys_errlist[];
-  extern int sys_nerr;
+  /* extern char *sys_errlist[]; */
+  /* extern int sys_nerr; */
   int en;
 
   en = errno;
