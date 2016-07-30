--- bsmtrace.c.orig	2014-01-14 22:51:19 UTC
+++ bsmtrace.c
@@ -92,7 +92,7 @@ bsmtrace_exit(int x)
 }
 
 void
-dprintf(char *fmt, ...)
+d_printf(char *fmt, ...)
 {
 	char buf[1024];
 	va_list ap;
