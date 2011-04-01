--- ffmpeg/libavformat/udp.c.orig	2011-03-16 13:49:21.000000000 +0100
+++ ffmpeg/libavformat/udp.c	2011-03-18 17:18:12.884305376 +0100
@@ -42,6 +42,8 @@
 #define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
 #endif
 
+#define IPPROTO_IPV6 41
+
 typedef struct {
     int udp_fd;
     int ttl;
