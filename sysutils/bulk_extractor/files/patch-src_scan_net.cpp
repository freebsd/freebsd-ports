--- src/scan_net.cpp.orig	2012-04-30 02:52:53.000000000 +0900
+++ src/scan_net.cpp	2012-04-30 02:53:04.000000000 +0900
@@ -28,6 +28,7 @@
 #include <tr1/unordered_set>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
@@ -233,8 +234,8 @@
     u_int8_t ip_ttl;			/* time to live */
     u_int8_t ip_p;			/* protocol */
     u_short ip_sum;			/* checksum */
-    uint32_t ip_src;
-    uint32_t ip_dst;	/* source and dest address */
+    struct in_addr ip_src;
+    struct in_addr ip_dst;	/* source and dest address */
 };
 #endif
 
