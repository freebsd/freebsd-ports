--- Source/WebCore/platform/network/DNS.h.orig	2021-09-22 23:05:58 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -33,6 +33,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif
 
