--- clients/ftp/ftp.c.orig	Thu Aug 17 00:38:44 2000
+++ clients/ftp/ftp.c	Tue Sep  7 20:41:35 2004
@@ -48,7 +48,15 @@
 #include <fcntl.h>
 #endif
 
+#ifdef HAVE_STDARG_H
+#include <stdarg.h>
+#define VA_START(a, b) va_start((a), (b))
+#define va_alist ...
+#define va_dcl
+#else
 #include <varargs.h>
+#define VA_START(a, b) va_start((a))
+#endif
 
 #ifdef FASCIST
 #include <syslog.h>
@@ -241,9 +249,8 @@
 }
 
 /*VARARGS*/
-int command(va_alist) va_dcl {
+int command(char *fmt, va_alist) va_dcl {
     va_list ap;
-    char *fmt;
     int r;
     Sig_t oldintr;
     
@@ -251,8 +258,7 @@
     if (debug) {
 	printf("---> ");
 
-	va_start(ap);
-	fmt = va_arg(ap, char *);
+	VA_START(ap, fmt);
 	if (strncmp("PASS ", fmt, 5) == 0)
 	    printf("PASS XXXX");
 	else 
@@ -271,8 +277,7 @@
 
     oldintr = Signal(SIGINT, cmdabort);
 
-    va_start(ap);
-    fmt = va_arg(ap, char *);
+    VA_START(ap, fmt);
     vfprintf(cout, fmt, ap);
     va_end(ap);
 
