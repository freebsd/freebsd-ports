--- print.c.orig	Tue Oct 28 01:43:36 2003
+++ print.c	Tue Oct 28 01:44:37 2003
@@ -36,21 +36,18 @@
     "@(#) $Header: /usr/staff/martinh/tcpview/RCS/print.c,v 1.1 1993/04/22 20:33:56 martinh Exp $ (UW)";
 #endif
 
-#include <varargs.h>
+#include <stdarg.h>
 
 extern char *StrPtr;
 extern void *Xfile;
 extern int Zflag;
 
-int printf(va_alist)
-     va_dcl
+int printf(char *fmt, ...)
 {
   va_list args;
-  char *fmt;
   int num;
 
-  va_start(args);
-  fmt = va_arg(args, char *);
+  va_start(args, fmt);
 #ifdef TCPDUMP  
   (void)vprintf(fmt, args);
 #else
