--- ./diffprobe.h.orig	2009-12-01 12:47:55.000000000 -0800
+++ ./diffprobe.h	2011-06-11 10:51:08.000000000 -0700
@@ -26,6 +26,8 @@
 #ifndef _DIFFPROBE_H_
 #define _DIFFPROBE_H_
 
+#include <netinet/in.h>
+
 #define VERSION 3
 #define RATE_FACTOR 0.9
 #define RATE_DROP_FACTOR 2
@@ -69,7 +71,7 @@
 int prober_bind_port(int port);
 
 double prober_sleep_resolution();
-void prober_sbusywait(struct timeval);
+inline void prober_sbusywait(struct timeval);
 void prober_swait(struct timeval, double sleepRes);
 struct timeval prober_packet_gap(struct timeval y, struct timeval x);
 
