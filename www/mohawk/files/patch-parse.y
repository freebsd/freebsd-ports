--- parse.y.orig	2017-01-27 06:01:59 UTC
+++ parse.y
@@ -30,8 +30,14 @@
 #include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 1000510
+#if defined(__FreeBSD__)
+#if __FreeBSD_version >= 1000510
+#  if __FreeBSD_version >= 1200000
+#include <sys/capsicum.h>
+#  else
 #include <sys/capability.h>
+#  endif
+#endif
 #endif
 
 #include <net/if.h>
