--- modules/dbparser/pdbtool/pdbtool.c.orig	2022-06-03 13:40:39 UTC
+++ modules/dbparser/pdbtool/pdbtool.c
@@ -1282,9 +1282,9 @@ main(int argc, char *argv[])
   ret = modes[mode].main(argc, argv);
   scratch_buffers_allocator_deinit();
   scratch_buffers_global_deinit();
-  stats_destroy();
   log_tags_global_deinit();
   log_msg_global_deinit();
+  stats_destroy();
 
   cfg_free(configuration);
   configuration = NULL;
