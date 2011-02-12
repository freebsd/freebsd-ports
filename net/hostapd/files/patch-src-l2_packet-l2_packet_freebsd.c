--- src/l2_packet/l2_packet_freebsd.c.orig	2011-02-05 17:11:19.000000000 -0800
+++ src/l2_packet/l2_packet_freebsd.c	2011-02-05 17:11:35.000000000 -0800
@@ -14,7 +14,7 @@
  */
 
 #include "includes.h"
-#if defined(__APPLE__) || defined(__GLIBC__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__GLIBC__)
 #include <net/bpf.h>
 #endif /* __APPLE__ */
 #include <pcap.h>
