--- libavformat/udp.c.orig	2015-01-06 18:58:59 UTC
+++ libavformat/udp.c
@@ -56,6 +56,8 @@
 #define UDP_TX_BUF_SIZE 32768
 #define UDP_MAX_PKT_SIZE 65536
 
+#define IPPROTO_IPV6 41
+
 typedef struct {
     const AVClass *class;
     int udp_fd;
