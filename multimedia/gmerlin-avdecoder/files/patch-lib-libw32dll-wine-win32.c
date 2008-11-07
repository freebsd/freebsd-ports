--- lib/libw32dll/wine/win32.c.orig	2008-01-11 22:27:11.000000000 +0300
+++ lib/libw32dll/wine/win32.c	2008-11-07 17:15:48.000000000 +0300
@@ -61,27 +61,6 @@
 #include <kstat.h>
 #endif
 
-#if HAVE_VSSCANF
-# ifndef __sun
-/*
- * On solaris, remove the prototype for now; it's incompatible with the one
- * from solaris9 stdio.h
- */
-int vsscanf( const char *str, const char *format, va_list ap);
-# endif
-#else
-/* system has no vsscanf.  try to provide one */
-static int vsscanf( const char *str, const char *format, va_list ap)
-{
-    long p1 = va_arg(ap, long);
-    long p2 = va_arg(ap, long);
-    long p3 = va_arg(ap, long);
-    long p4 = va_arg(ap, long);
-    long p5 = va_arg(ap, long);
-    return sscanf(str, format, p1, p2, p3, p4, p5);
-}
-#endif
-
 char* win32_def_path = WIN32_PATH;
 
 static void do_cpuid(unsigned int ax, unsigned int *regs)
