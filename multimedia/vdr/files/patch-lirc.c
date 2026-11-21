--- lirc.c.orig	2026-06-01 16:59:58 UTC
+++ lirc.c
@@ -10,8 +10,12 @@
  */
 
 #include "lirc.h"
+#ifdef __linux__
 #include <linux/version.h>
 #define HAVE_KERNEL_LIRC (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
+#else
+#define HAVE_KERNEL_LIRC 0
+#endif
 // cLircUsrRemote
 #include <netinet/in.h>
 #include <sys/socket.h>
