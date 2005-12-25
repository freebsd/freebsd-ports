--- libk3b/core/k3bglobals.h.orig	Mon Dec 12 10:33:27 2005
+++ libk3b/core/k3bglobals.h	Wed Dec 14 23:57:17 2005
@@ -21,6 +21,10 @@
 #include <kio/global.h>
 #include <kurl.h>
 #include <k3bdevicetypes.h>
+#ifdef Q_OS_FREEBSD
+#define stat64 stat
+#define lstat64 lstat
+#endif
 
 class KConfig;
 class K3bVersion;
