--- bsmtrace.c.orig	2014-01-14 22:51:19 UTC
+++ bsmtrace.c
@@ -30,6 +30,7 @@
 #include "includes.h"
 
 static int	daemonized;	/* daemonized or not? */
+int	audit_pipe_fd;
 
 /*
  * If we are going to be daemonized, write out a pid file to
@@ -92,7 +92,7 @@ bsmtrace_exit(int x)
 }
 
 void
-dprintf(char *fmt, ...)
+d_printf(char *fmt, ...)
 {
 	char buf[1024];
 	va_list ap;
