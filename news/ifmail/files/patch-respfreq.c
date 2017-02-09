--- ifcico/respfreq.c.orig	1997-07-12 23:38:51 UTC
+++ ifcico/respfreq.c
@@ -17,7 +17,11 @@ int re_exec(char*);
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
@@ -43,7 +47,7 @@ static file_list *resplist(char*);
 
 #ifndef NOFREQREPORT
 static void attach_report(file_list**);
-static void add_report();
+static void add_report(char *fmt,...);
 static char *report_text=NULL;
 static unsigned long report_total=0L;
 #endif
@@ -519,15 +523,25 @@ file_list **fl;
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
