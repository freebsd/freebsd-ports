--- loader/win32.c.orig	Thu Jan 18 11:06:11 2007
+++ loader/win32.c	Thu Jan 18 11:06:32 2007
@@ -66,7 +66,7 @@
 #include <kstat.h>
 #endif
 
-#if HAVE_VSSCANF
+#if 1
 int vsscanf( const char *str, const char *format, va_list ap);
 #else
 /* system has no vsscanf.  try to provide one */
