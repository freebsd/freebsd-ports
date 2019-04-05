--- src/3rdparty/chromium/net/socket/socks5_client_socket.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/socket/socks5_client_socket.cc
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include <utility>
 
 #include "base/callback_helpers.h"
