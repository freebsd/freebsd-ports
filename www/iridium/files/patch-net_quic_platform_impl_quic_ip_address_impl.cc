--- net/quic/platform/impl/quic_ip_address_impl.cc.orig	2018-08-16 11:22:27.420793000 +0200
+++ net/quic/platform/impl/quic_ip_address_impl.cc	2018-08-16 11:23:09.202594000 +0200
@@ -12,6 +12,7 @@
 #include <ws2bth.h>
 #elif defined(OS_POSIX)
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 using std::string;
