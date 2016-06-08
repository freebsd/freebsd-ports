--- ./net/base/net_util.h.orig	2014-04-30 22:43:05.000000000 +0200
+++ ./net/base/net_util.h	2014-05-04 14:38:48.000000000 +0200
@@ -13,6 +13,9 @@
 #elif defined(OS_POSIX)
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 #include <string>
