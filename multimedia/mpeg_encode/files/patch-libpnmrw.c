--- ./libpnmrw.c.orig
+++ ./libpnmrw.c
@@ -27,6 +27,7 @@
 /* #define MSDOS */
 #endif
 
+#include <errno.h>
 #include <stdio.h>
 #include "libpnmrw.h"
 
@@ -126,8 +127,10 @@
   pm_perror( reason )
 char* reason;
 {
+#ifndef __FreeBSD__
   extern char* sys_errlist[];
   extern int errno;
+#endif
   char* e;
 
   e = sys_errlist[errno];
