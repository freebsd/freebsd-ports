--- src/socket.hh.orig	2025-03-20 09:59:25 UTC
+++ src/socket.hh
@@ -10,8 +10,8 @@
 #include <ws2ipdef.h>
 #include <WS2tcpip.h>
 #else
-#include <netinet/ip.h>
 #include <arpa/inet.h>
+#include <netinet/ip.h>
 #include <sys/uio.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
