--- ifcico/respfreq.c.orig	Sun Jul 13 01:38:51 1997
+++ ifcico/respfreq.c	Mon Aug 11 17:34:09 2003
@@ -17,7 +17,11 @@
 #include "lutil.h"
 #include "config.h"
 #ifndef NOFREQREPORT
+#ifdef HAS_STDARG_H
+#include <stdarg.h>
+#else
 #include <varargs.h>
+#endif
 #include "ftnmsg.h"
 #endif
 #include "version.h"
@@ -43,7 +47,7 @@
 
 #ifndef NOFREQREPORT
 static void attach_report(file_list**);
-static void add_report();
+static void add_report(char *fmt,...);
 static char *report_text=NULL;
 static unsigned long report_total=0L;
 #endif
@@ -519,15 +523,25 @@
 	report_text=NULL;
 }
 
+#ifdef HAS_STDARG_H
+static void add_report(char *fmt, ...)
+{
+	va_list	args;
+#else
 static void add_report(va_alist)
 va_dcl
 {
-	va_list args;
-	char *fmt;
+	va_list	args;
+	char	*fmt;
+#endif
 	char buf[1024];
 
+#ifdef HAS_STDARG_H
+	va_start(args, fmt);
+#else
 	va_start(args);
-	fmt=va_arg(args,char*);
+	fmt=va_arg(args, char*);
+#endif
 
 	if (report_text == NULL)
 	{
