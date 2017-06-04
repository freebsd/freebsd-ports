--- src/3rdparty/chromium/ppapi/shared_impl/private/net_address_private_impl.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/ppapi/shared_impl/private/net_address_private_impl.cc
@@ -24,6 +24,7 @@
 #include <ws2tcpip.h>
 #elif defined(OS_POSIX) && !defined(OS_NACL)
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #endif
