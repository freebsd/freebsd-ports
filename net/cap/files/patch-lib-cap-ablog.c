--- lib/cap/ablog.c.foo	Mon Nov  4 16:43:02 2002
+++ lib/cap/ablog.c	Mon Nov  4 16:43:11 2002
@@ -91,7 +91,7 @@
 #endif USEVPRINTF
   int saveerr;
   extern int errno;
-  extern int sys_nerr;
+  extern __const int sys_nerr;
 #ifndef __FreeBSD__
   extern char *sys_errlist[];
 #endif
