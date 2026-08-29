--- src/imt_plugin.c.orig	2024-08-01 20:49:09 UTC
+++ src/imt_plugin.c
@@ -158,7 +158,7 @@ void imt_plugin(int pipe_fd, struct configuration *cfg
   if (!config.imt_plugin_path) config.imt_plugin_path = path; 
   if (!config.buckets) config.buckets = MAX_HOSTS;
 
-  init_memory_pool_table();
+  init_memory_pool_table(config);
   if (mpd == NULL) {
     Log(LOG_ERR, "ERROR ( %s/%s ): unable to allocate memory pools table\n", config.name, config.type);
     exit_gracefully(1);
