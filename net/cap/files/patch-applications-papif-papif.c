--- applications/papif/papif.c.orig	Sat Mar 20 12:14:20 2004
+++ applications/papif/papif.c	Sat Mar 20 12:19:52 2004
@@ -1801,16 +1801,13 @@
 dolog(fmt, a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac,ad,ae,af)
 char *fmt;
 #else
-dolog(va_alist)
+dolog(register char *fmt, ...)
-va_dcl
 #endif
 {
 #ifdef USEVPRINTF
-  register char *fmt;
   va_list args;
 
-  va_start(args);
-  fmt = va_arg(args, char *);
+  va_start(args, fmt);
   if (jobout)
     vfprintf(jobout, fmt, args);
   vfprintf(stderr, fmt, args);
