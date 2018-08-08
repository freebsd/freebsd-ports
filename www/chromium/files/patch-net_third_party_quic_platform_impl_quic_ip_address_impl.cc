--- net/third_party/quic/platform/impl/quic_ip_address_impl.cc.orig	2018-08-04 20:21:44.470242000 +0200
+++ net/third_party/quic/platform/impl/quic_ip_address_impl.cc	2018-08-04 20:22:01.700604000 +0200
@@ -13,6 +13,7 @@
 #include <ws2bth.h>
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 using std::string;
