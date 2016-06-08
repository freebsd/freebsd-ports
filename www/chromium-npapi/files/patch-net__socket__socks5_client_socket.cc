--- ./net/socket/socks5_client_socket.cc.orig	2014-04-30 22:43:08.000000000 +0200
+++ ./net/socket/socks5_client_socket.cc	2014-05-04 14:38:48.000000000 +0200
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include "base/basictypes.h"
 #include "base/callback_helpers.h"
 #include "base/compiler_specific.h"
