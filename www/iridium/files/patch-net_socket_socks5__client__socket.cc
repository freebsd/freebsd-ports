--- net/socket/socks5_client_socket.cc.orig	2024-08-01 05:47:53 UTC
+++ net/socket/socks5_client_socket.cc
@@ -24,6 +24,9 @@
 #include "net/log/net_log_event_type.h"
 #include "net/traffic_annotation/network_traffic_annotation.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
+
 namespace net {
 
 const unsigned int SOCKS5ClientSocket::kGreetReadHeaderSize = 2;
