--- ./components/gatherer/standard/pstext/pstext/common.c.orig	Fri Aug  1 13:50:18 2003
+++ ./components/gatherer/standard/pstext/pstext/common.c	Fri Aug  1 14:09:05 2003
@@ -6,7 +6,11 @@
 
 static char RCSid[] = "common.c,v 1.4 1995/01/20 23:03:20 hardy Exp";
 
+#ifdef __STRICT_ANSI__
+#include <stdarg.h>
+#else
 #include <varargs.h>
+#endif
 
 void exit();
 char *malloc();
@@ -143,6 +147,12 @@
 }
 
 
+#ifdef __STRICT_ANSI__
+void error(char *fmt, ...)
+{
+	va_list ap;
+	va_start(ap,fmt);
+#else
 void error(fmt, va_alist)
 char *fmt;
 va_dcl
@@ -150,6 +160,7 @@
 	va_list ap;
 
 	va_start(ap);
+#endif
 	Sprint(2, "pstext: Line %d: ", line_count);
 	Sprintv(2, fmt, ap);
 	exit(1);
