--- ./net/socket/socks5_client_socket.cc.orig	2014-08-20 21:02:27.000000000 +0200
+++ ./net/socket/socks5_client_socket.cc	2014-08-22 15:06:26.000000000 +0200
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include "base/basictypes.h"
 #include "base/callback_helpers.h"
 #include "base/compiler_specific.h"
