--- util.h.orig	2019-11-15 11:52:14 UTC
+++ util.h
@@ -25,7 +25,7 @@
 #include <netinet/ip.h>
 #include <sys/types.h>
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define POLLRDHUP 0
 /* uClibc may does not have clock_nanosleep() */
 #elif !defined (__UCLIBC__) || \
@@ -60,7 +60,7 @@ typedef union
  * Raw udp packet structure with flexible-array payload
  *****************************************************************************/
 struct udprawpkt {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
     struct  ip iph;
 #else
     struct  iphdr iph;
