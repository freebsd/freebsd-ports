--- net/third_party/quic/platform/impl/quic_ip_address_impl.cc.orig	2019-03-11 22:01:01 UTC
+++ net/third_party/quic/platform/impl/quic_ip_address_impl.cc
@@ -13,6 +13,7 @@
 #include <ws2bth.h>
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 using std::string;
