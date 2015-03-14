--- libavformat/udp.c.orig	2015-03-06 23:35:33.000000000 +0100
+++ libavformat/udp.c	2015-03-14 07:54:42.860295960 +0100
@@ -71,6 +71,8 @@
 #define UDP_MAX_PKT_SIZE 65536
 #define UDP_HEADER_SIZE 8
 
+#define IPPROTO_IPV6 41
+
 typedef struct UDPContext {
     const AVClass *class;
     int udp_fd;
