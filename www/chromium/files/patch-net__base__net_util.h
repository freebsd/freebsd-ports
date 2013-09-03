--- net/base/net_util.h.orig	2013-09-01 00:45:45.000000000 +0300
+++ net/base/net_util.h	2013-09-01 00:47:35.000000000 +0300
@@ -13,6 +13,9 @@
 #elif defined(OS_POSIX)
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 #include <list>
