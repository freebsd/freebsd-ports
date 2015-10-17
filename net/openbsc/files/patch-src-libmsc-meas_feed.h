--- src/libmsc/meas_feed.h.orig	2015-02-10 22:03:25 UTC
+++ src/libmsc/meas_feed.h
@@ -3,6 +3,10 @@
 
 #include <stdint.h>
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
+
 int meas_feed_cfg_set(const char *dst_host, uint16_t dst_port);
 void meas_feed_cfg_get(char **host, uint16_t *port);
 
