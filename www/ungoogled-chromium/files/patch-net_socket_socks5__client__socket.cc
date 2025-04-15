--- net/socket/socks5_client_socket.cc.orig	2025-04-15 08:30:07 UTC
+++ net/socket/socks5_client_socket.cc
@@ -23,6 +23,9 @@
 #include "net/log/net_log_event_type.h"
 #include "net/traffic_annotation/network_traffic_annotation.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
+
 namespace net {
 
 const unsigned int SOCKS5ClientSocket::kGreetReadHeaderSize = 2;
