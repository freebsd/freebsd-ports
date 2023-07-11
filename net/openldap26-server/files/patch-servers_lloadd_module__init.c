--- servers/lloadd/module_init.c.orig	2023-02-08 18:53:35 UTC
+++ servers/lloadd/module_init.c
@@ -151,14 +151,13 @@ lload_back_initialize( BackendInfo *bi )
 {
     bi->bi_flags = SLAP_BFLAG_STANDALONE;
     bi->bi_open = lload_back_open;
-    bi->bi_config = config_generic_wrapper;
     bi->bi_pause = lload_pause_cb;
     bi->bi_unpause = lload_unpause_cb;
     bi->bi_close = lload_back_close;
     bi->bi_destroy = lload_back_destroy;
 
     bi->bi_db_init = 0;
-    bi->bi_db_config = 0;
+    bi->bi_db_config = config_generic_wrapper;
     bi->bi_db_open = 0;
     bi->bi_db_close = 0;
     bi->bi_db_destroy = 0;
