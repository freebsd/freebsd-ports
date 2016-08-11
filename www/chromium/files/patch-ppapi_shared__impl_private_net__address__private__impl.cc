--- ppapi/shared_impl/private/net_address_private_impl.cc.orig	2016-05-11 19:02:25 UTC
+++ ppapi/shared_impl/private/net_address_private_impl.cc
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
