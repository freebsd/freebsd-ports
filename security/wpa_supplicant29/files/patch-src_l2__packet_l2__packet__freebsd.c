--- src/l2_packet/l2_packet_freebsd.c.orig	2018-12-02 11:34:59.000000000 -0800
+++ src/l2_packet/l2_packet_freebsd.c	2018-12-05 23:18:27.612433000 -0800
@@ -8,7 +8,8 @@
  */
 
 #include "includes.h"
-#if defined(__APPLE__) || defined(__GLIBC__)
+#include <sys/param.h>
+#if defined(__APPLE__) || defined(__GLIBC__) || defined(__FreeBSD_version)
 #include <net/bpf.h>
 #endif /* __APPLE__ */
 #include <pcap.h>
