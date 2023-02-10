Index: Source/WebCore/platform/network/DNS.h
--- Source/WebCore/platform/network/DNS.h.orig
+++ Source/WebCore/platform/network/DNS.h
@@ -34,6 +34,7 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+#include <sys/socket.h> /* AF_INET, AF_INET6 */
 #endif
 
 namespace WebCore {
