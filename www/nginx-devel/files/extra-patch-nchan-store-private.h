--- ../nchan-1.2.7/src/store/memory/store-private.h.orig	2020-09-20 13:11:33.781569000 +0200
+++ ../nchan-1.2.7/src/store/memory/store-private.h	2020-09-20 13:11:48.679855000 +0200
@@ -172,6 +172,6 @@
 void memstore_chanhead_release(memstore_channel_head_t *ch, char *label);
 void memstore_chanhead_reserve(memstore_channel_head_t *ch, const char *label);
 
-uint16_t  memstore_worker_generation; //times nginx has been restarted + 1
+extern uint16_t  memstore_worker_generation; //times nginx has been restarted + 1
 
 #endif /*MEMSTORE_PRIVATE_HEADER*/
