--- print.c.orig	1993-04-22 20:40:29 UTC
+++ print.c
@@ -36,21 +36,18 @@ static char rcsid[] =
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
