--- clients/lcdproc/chrono.c.orig	Sat Dec 29 06:52:39 2001
+++ clients/lcdproc/chrono.c	Tue May  6 05:07:49 2003
@@ -62,6 +62,8 @@
 #include <sys/dkstat.h>
 #endif
 
+#include <sys/resource.h>
+
 #if FREEBSD
 /* definitions for indices in the nlist array */
 /* from /usr/src/src.bin/top/machine.c */
