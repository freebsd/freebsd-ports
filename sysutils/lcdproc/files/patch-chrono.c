--- clients/lcdproc/chrono.c.orig	Tue Jan 18 19:57:44 2005
+++ clients/lcdproc/chrono.c	Tue Jan 18 19:59:30 2005
@@ -62,6 +62,8 @@
 #include <sys/dkstat.h>
 #endif
 
+#include <sys/resource.h>
+
 #if FREEBSD
 /* definitions for indices in the nlist array */
 /* from /usr/src/src.bin/top/machine.c */
