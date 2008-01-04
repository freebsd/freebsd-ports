--- src/barnyard.h	2004-05-01 12:43:29.000000000 -0400
+++ src/barnyard.h	2007-08-11 23:22:53.000000000 -0400
@@ -34,7 +34,8 @@
 
 typedef struct _SnortPktHeader
 {
-    struct timeval ts;     /* packet timestamp */
+    // struct timeval ts;     /* packet timestamp */
+    struct pcap_timeval ts;     /* packet timestamp */
     u_int32_t caplen;      /* packet capture length */
     u_int32_t pktlen;      /* packet "real" length */
 } SnortPktHeader;
