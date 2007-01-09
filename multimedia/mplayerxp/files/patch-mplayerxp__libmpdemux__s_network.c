--- mplayerxp/libmpdemux/s_network.c.orig	Sat Jul  2 18:59:02 2005
+++ mplayerxp/libmpdemux/s_network.c	Sun Oct  1 23:50:43 2006
@@ -46,6 +46,10 @@
   return 0;
 }
 
+#ifndef TEMP_FAILURE_RETRY
+#define TEMP_FAILURE_RETRY(x) (x)
+#endif
+
 static int __FASTCALL__ network_read(stream_t *stream,stream_packet_t*sp)
 {
     network_priv_t *p=stream->priv;
