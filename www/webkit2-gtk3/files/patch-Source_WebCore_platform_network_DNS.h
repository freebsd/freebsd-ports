--- Source/WebCore/platform/network/DNS.h.orig	2020-09-30 07:03:48 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -29,6 +29,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif
 
