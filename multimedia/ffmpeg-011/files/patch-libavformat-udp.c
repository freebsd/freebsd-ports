--- libavformat/udp.c.orig	2009-05-15 17:24:45.000000000 +0200
+++ libavformat/udp.c	2009-05-15 17:27:17.000000000 +0200
@@ -45,6 +45,8 @@
 #define IN6_IS_ADDR_MULTICAST(a) (((uint8_t *) (a))[0] == 0xff)
 #endif
 
+#define IPPROTO_IPV6 41
+
 typedef struct {
     int udp_fd;
     int ttl;
