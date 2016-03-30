--- net/socket/socks5_client_socket.cc.orig	2016-03-05 12:01:24.173856244 +0100
+++ net/socket/socks5_client_socket.cc	2016-03-05 12:01:43.793854738 +0100
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include <utility>
 
 #include "base/callback_helpers.h"
