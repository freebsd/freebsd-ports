--- src/reception_flow.hh.orig	2025-03-20 09:59:25 UTC
+++ src/reception_flow.hh
@@ -16,6 +16,7 @@
 #ifdef _WIN32
 #include <ws2ipdef.h>
 #else
+#include <arpa/inet.h>
 #include <netinet/ip.h>
 #include <sys/socket.h>
 #endif
