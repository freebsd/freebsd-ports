--- src/xitk/network.c.orig	Mon Mar  3 23:43:41 2003
+++ src/xitk/network.c	Tue Mar 25 00:10:12 2003
@@ -48,6 +48,7 @@
 #include <time.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#include <sys/select.h>
 #include <sys/stat.h>
 #include <sys/signal.h>
 #include <sys/time.h>
