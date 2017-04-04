--- xbmc/linux/PlatformDefs.h.orig	2017-03-04 19:20:36 UTC
+++ xbmc/linux/PlatformDefs.h
@@ -52,6 +52,7 @@
 #endif
 #elif defined(TARGET_FREEBSD)
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #else
