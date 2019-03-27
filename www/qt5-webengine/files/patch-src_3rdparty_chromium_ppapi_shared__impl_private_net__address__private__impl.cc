--- src/3rdparty/chromium/ppapi/shared_impl/private/net_address_private_impl.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ppapi/shared_impl/private/net_address_private_impl.cc
@@ -27,6 +27,9 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 // The net address interface doesn't have a normal C -> C++ thunk since it
