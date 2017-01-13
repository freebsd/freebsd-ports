--- util.h.orig	2016-10-07 14:32:44 UTC
+++ util.h
@@ -24,7 +24,7 @@
 #include <netinet/udp.h>
 #include <netinet/ip.h>
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define POLLRDHUP 0
 /* uClibc may does not have clock_nanosleep() */
 #elif !defined (__UCLIBC__) || \
@@ -59,7 +59,7 @@ typedef union
  *****************************************************************************/
 struct udprawpkt {
 #if !defined(__APPLE__)
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     struct  ip iph;
 #else
     struct  iphdr iph;
