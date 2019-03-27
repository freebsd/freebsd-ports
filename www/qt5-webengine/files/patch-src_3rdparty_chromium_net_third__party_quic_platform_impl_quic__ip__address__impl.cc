--- src/3rdparty/chromium/net/third_party/quic/platform/impl/quic_ip_address_impl.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/third_party/quic/platform/impl/quic_ip_address_impl.cc
@@ -13,6 +13,7 @@
 #include <ws2bth.h>
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 using std::string;
