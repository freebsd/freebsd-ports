--- clients/lcdproc/cpu.c.orig	Thu Jan  3 13:32:42 2002
+++ clients/lcdproc/cpu.c	Tue May  6 05:08:51 2003
@@ -60,6 +60,9 @@
 #include <sys/dkstat.h>
 #endif
 
+#include <sys/time.h>
+#include <sys/resource.h>
+
 #if FREEBSD
 /* definitions for indices in the nlist array */
 /* from /usr/src/src.bin/top/machine.c */
