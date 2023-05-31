--- plugins/obs-outputs/ftl-sdk/libftl/ingest.c.orig	2020-02-18 17:21:01 UTC
+++ plugins/obs-outputs/ftl-sdk/libftl/ingest.c
@@ -335,7 +335,7 @@ cleanup:
   
   ftl->ingest_count = total_ingest_cnt;
   
-  return total_ingest_cnt;
+  return (OS_THREAD_ROUTINE)total_ingest_cnt;
 }
 
 char * ingest_find_best(ftl_stream_configuration_private_t *ftl) {
