--- src/l2_packet/l2_packet_freebsd.c.orig	2023-10-30 10:53:18.000000000 -0700
+++ src/l2_packet/l2_packet_freebsd.c	2023-10-30 14:10:36.396969000 -0700
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
