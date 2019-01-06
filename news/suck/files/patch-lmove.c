--- lmove.c.orig	2018-08-01 13:54:24 UTC
+++ lmove.c
@@ -28,6 +28,7 @@
 #include <sys/stat.h>
 #include <errno.h>
 #include <signal.h>
+#include <sys/syslimits.h>
 
 #ifdef DMALLOC
 #include <dmalloc.h>
