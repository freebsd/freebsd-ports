--- kover/cdrom.h.orig	Mon Dec 29 03:57:18 2003
+++ kover/cdrom.h	Mon Dec 29 03:57:39 2003
@@ -41,6 +41,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#endif
+
 #ifdef HAVE_LINUX_CDROM_H
 #include <linux/cdrom.h>
 #endif
