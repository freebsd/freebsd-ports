--- clients/lcdproc/cpu.c.orig	Tue Jan 18 19:58:47 2005
+++ clients/lcdproc/cpu.c	Tue Jan 18 19:59:52 2005
@@ -60,6 +60,9 @@
 #include <sys/dkstat.h>
 #endif
 
+#include <sys/time.h>
+#include <sys/resource.h>
+
 #if FREEBSD
 /* definitions for indices in the nlist array */
 /* from /usr/src/src.bin/top/machine.c */
