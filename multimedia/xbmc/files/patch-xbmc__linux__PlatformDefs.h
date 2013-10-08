--- xbmc/linux/PlatformDefs.h.orig	2013-05-03 07:57:41.000000000 +0200
+++ xbmc/linux/PlatformDefs.h	2013-10-07 23:03:51.032581268 +0200
@@ -55,6 +55,7 @@
 #include <stdio.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
+#include <stdlib.h>
 #else
 #include <sys/sysinfo.h>
 #endif
