--- libavformat/udp.c.orig	2015-06-19 20:44:53 UTC
+++ libavformat/udp.c
@@ -71,6 +71,8 @@
 #define UDP_MAX_PKT_SIZE 65536
 #define UDP_HEADER_SIZE 8
 
+#define IPPROTO_IPV6 41
+
 typedef struct UDPContext {
     const AVClass *class;
     int udp_fd;
