--- src/l2_packet/l2_packet_freebsd.c.orig	2022-01-16 12:51:29.000000000 -0800
+++ src/l2_packet/l2_packet_freebsd.c	2022-04-14 07:23:26.534960000 -0700
@@ -8,7 +8,10 @@
  */
 
 #include "includes.h"
-#if defined(__APPLE__) || defined(__GLIBC__)
+#if defined(__FreeBSD__) \
+ || defined(__DragonFly__) \
+ || defined(__APPLE__) \
+ || defined(__GLIBC__)
 #include <net/bpf.h>
 #endif /* __APPLE__ */
 #include <pcap.h>
