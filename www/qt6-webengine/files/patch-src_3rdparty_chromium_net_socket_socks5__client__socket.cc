--- src/3rdparty/chromium/net/socket/socks5_client_socket.cc.orig	2022-04-21 18:48:31 UTC
+++ src/3rdparty/chromium/net/socket/socks5_client_socket.cc
@@ -19,6 +19,9 @@
 #include "net/log/net_log_event_type.h"
 #include "net/traffic_annotation/network_traffic_annotation.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
+
 namespace net {
 
 const unsigned int SOCKS5ClientSocket::kGreetReadHeaderSize = 2;
