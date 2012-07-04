--- diffprobe.h.orig	2012-01-25 04:33:22.000000000 +0800
+++ diffprobe.h	2012-06-07 16:32:41.050222578 +0800
@@ -26,6 +26,8 @@
 #ifndef _DIFFPROBE_H_
 #define _DIFFPROBE_H_
 
+#include <netinet/in.h>
+
 #define VERSION 4
 #define RATE_FACTOR 0.9
 #define RATE_DROP_FACTOR 2
@@ -69,7 +71,7 @@
 int prober_bind_port(int port);
 
 double prober_sleep_resolution();
-void prober_sbusywait(struct timeval);
+inline void prober_sbusywait(struct timeval);
 void prober_swait(struct timeval, double sleepRes);
 struct timeval prober_packet_gap(struct timeval y, struct timeval x);
 
