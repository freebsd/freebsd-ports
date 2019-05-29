--- src/framework/socketreceiver.h.orig	2018-12-20 14:40:17 UTC
+++ src/framework/socketreceiver.h
@@ -5,6 +5,10 @@
 
 #include <sys/socket.h>
 #include "serversocket.h"
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 class SocketConnection;
 
 class SocketReceiver : public ServerSocket {
