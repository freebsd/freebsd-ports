--- net/socket/socks5_client_socket.cc.orig	2012-07-26 22:30:09.628651909 +0300
+++ net/socket/socks5_client_socket.cc	2012-07-26 22:30:41.781651802 +0300
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include "base/basictypes.h"
 #include "base/compiler_specific.h"
 #include "base/debug/trace_event.h"
