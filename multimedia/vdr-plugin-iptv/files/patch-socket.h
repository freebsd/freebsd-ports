--- a/socket.h
+++ b/socket.h
@@ -9,6 +9,7 @@
 #define __IPTV_SOCKET_H
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 class cIptvSocket {
 protected:
