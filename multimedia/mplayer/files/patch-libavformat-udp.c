--- ffmpeg/libavformat/udp.c.orig	2015-03-30 19:20:06.000000000 +0200
+++ ffmpeg/libavformat/udp.c	2015-04-03 13:29:34.228251670 +0200
@@ -71,6 +71,8 @@
 #define UDP_MAX_PKT_SIZE 65536
 #define UDP_HEADER_SIZE 8
 
+#define IPPROTO_IPV6 41
+
 typedef struct UDPContext {
     const AVClass *class;
     int udp_fd;
