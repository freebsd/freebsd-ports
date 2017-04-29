--- net/quic/platform/impl/quic_ip_address_impl.cc.orig	2017-04-19 19:06:36 UTC
+++ net/quic/platform/impl/quic_ip_address_impl.cc
@@ -12,6 +12,7 @@
 #include <ws2bth.h>
 #elif defined(OS_POSIX)
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 using std::string;
