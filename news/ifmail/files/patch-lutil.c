--- iflib/lutil.c.orig	1998-02-01 22:11:53 UTC
+++ iflib/lutil.c
@@ -4,7 +4,11 @@
 #include <stdio.h>
 #include <sys/stat.h>
 #include <string.h>
+#ifdef HAS_STDARG_H
+#include <stdarg.h>
+#else
 #include <varargs.h>
+#endif
 #include <errno.h>
 #include <time.h>
 #ifdef HAS_SYSLOG
@@ -126,17 +130,27 @@ char c;
 		syslog(level,"\terrno=%d : %s",\
                         errno,strerror(errno));
 
+#ifdef HAS_STDARG_H
+void loginf(char *fmt, ...)
+{
+	va_list	args;
+#else
 void loginf(va_alist)
 va_dcl
 {
 	va_list	args;
 	char	*fmt;
+#endif
 #ifndef HAS_SYSLOG
 	int	oldmask;
 #endif
 
+#ifdef HAS_STDARG_H
+	va_start(args, fmt);
+#else
 	va_start(args);
 	fmt=va_arg(args, char*);
+#endif
 	if (verbose)
 	{
 		PRINT_DEBUG(fmt,args);
@@ -166,17 +180,27 @@ va_dcl
 	return;
 }
 
+#ifdef HAS_STDARG_H
+void logerr(char *fmt, ...)
+{
+	va_list	args;
+#else
 void logerr(va_alist)
 va_dcl
 {
 	va_list	args;
 	char	*fmt;
+#endif
 #ifndef HAS_SYSLOG
 	int	oldmask;
 #endif
 
+#ifdef HAS_STDARG_H
+	va_start(args, fmt);
+#else
 	va_start(args);
 	fmt=va_arg(args, char*);
+#endif
 	if (verbose)
 	{
 		PRINT_DEBUG(fmt,args);
@@ -206,16 +230,26 @@ va_dcl
 	return;
 }
 
+#ifdef HAS_STDARG_H
+void debug(unsigned long level, char *fmt, ...)
+{
+	va_list	args;
+#else
 void debug(va_alist)
 va_dcl
 {
 	va_list	args;
 	unsigned long	level;
 	char	*fmt;
+#endif
 
+#ifdef HAS_STDARG_H
+	va_start(args, fmt);
+#else
 	va_start(args);
 	level=va_arg(args, unsigned long);
 	fmt=va_arg(args, char*);
+#endif
 
 	if ((verbose && (level == 0)) || (verbose & (1 << (level-1))))
 	{
