--- vprintf.c.orig	Sat Aug 21 02:46:35 1993
+++ vprintf.c	Wed Jul 30 02:59:04 2003
@@ -59,7 +59,7 @@
  */
 
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 #ifdef DOPRINT_VA
 /* 
@@ -118,9 +118,16 @@
 {
 	FILE fakebuf;
 
+#ifdef __hpux
+	fakebuf._flag = _IODUMMY+_IOWRT;/* no _IOWRT: avoid stdio bug */
+	fakebuf._base = fakebuf._ptr = s;
+	fakebuf._cnt = n-1;
+	fakebuf.__fileL = fakebuf.__fileH = 0xff;
+#else
 	fakebuf._flag = _IOSTRG+_IOWRT;	/* no _IOWRT: avoid stdio bug */
 	fakebuf._ptr = s;
 	fakebuf._cnt = n-1;
+#endif
 	_doprnt(fmt, args, &fakebuf);
 	fakebuf._cnt++;
 	putc('\0', &fakebuf);
