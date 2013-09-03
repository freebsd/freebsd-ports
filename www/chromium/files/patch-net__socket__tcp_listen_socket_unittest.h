--- net/socket/tcp_listen_socket_unittest.h.orig	2013-09-01 00:30:34.000000000 +0300
+++ net/socket/tcp_listen_socket_unittest.h	2013-09-01 00:31:11.000000000 +0300
@@ -13,6 +13,9 @@
 #include <arpa/inet.h>
 #include <errno.h>
 #include <sys/socket.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 #include "base/basictypes.h"
