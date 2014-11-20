--- net/base/net_util.h.orig	2014-10-10 09:15:31 UTC
+++ net/base/net_util.h
@@ -13,6 +13,9 @@
 #elif defined(OS_POSIX)
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 #include <string>
