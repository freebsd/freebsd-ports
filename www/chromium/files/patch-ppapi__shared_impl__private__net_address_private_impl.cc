--- ppapi/shared_impl/private/net_address_private_impl.cc.orig	2016-03-05 12:05:33.124839671 +0100
+++ ppapi/shared_impl/private/net_address_private_impl.cc	2016-03-05 12:06:39.850834354 +0100
@@ -26,9 +26,12 @@
 #include <arpa/inet.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // This is a bit evil, but it's standard operating procedure for |s6_addr|....
 #define s6_addr16 __u6_addr.__u6_addr16
 #endif
