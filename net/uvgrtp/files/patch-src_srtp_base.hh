--- src/srtp/base.hh.orig	2025-03-20 09:59:25 UTC
+++ src/srtp/base.hh
@@ -7,8 +7,8 @@
 #include <mswsock.h>
 #include <inaddr.h>
 #else
-#include <netinet/ip.h>
 #include <arpa/inet.h>
+#include <netinet/ip.h>
 #endif
 
 #include <cstdint>
