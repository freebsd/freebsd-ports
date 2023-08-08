--- src/sqlite3_plugin.c.orig	2022-12-31 19:17:17 UTC
+++ src/sqlite3_plugin.c
@@ -533,7 +533,7 @@ void SQLI_cache_purge(struct db_cache *queue[], int in
   if (sql_pqq_ptr) goto start;
   
   idata->elap_time = time(NULL)-start; 
-  Log(LOG_INFO, "INFO ( %s/%s ): *** Purging cache - END (PID: %u, QN: %u/%u, ET: %lu) ***\n", 
+  Log(LOG_INFO, "INFO ( %s/%s ): *** Purging cache - END (PID: %u, QN: %u/%u, ET: %zu) ***\n", 
 		config.name, config.type, writer_pid, idata->qn, saved_index, idata->elap_time); 
 
   if (config.sql_trigger_exec) {
