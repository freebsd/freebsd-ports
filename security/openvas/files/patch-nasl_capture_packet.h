--- nasl/capture_packet.h	2020-12-31 17:18:54.965710000 -0500
+++ nasl/capture_packet.h	2020-12-31 17:18:25.229452000 -0500
@@ -19,6 +19,7 @@
 #ifndef CAPTURE_PACKET_H
 #define CAPTURE_PACKET_H
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/ip6.h>
 
