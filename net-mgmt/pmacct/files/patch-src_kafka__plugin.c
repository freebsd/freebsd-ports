--- src/kafka_plugin.c.orig	2020-05-10 13:57:54 UTC
+++ src/kafka_plugin.c
@@ -875,7 +875,7 @@ void kafka_cache_purge(struct chained_cache *queue[], 
 
   p_kafka_close(&kafkap_kafka_host, FALSE);
 
-  Log(LOG_INFO, "INFO ( %s/%s ): *** Purging cache - END (PID: %u, QN: %u/%u, ET: %lu) ***\n",
+  Log(LOG_INFO, "INFO ( %s/%s ): *** Purging cache - END (PID: %u, QN: %u/%u, ET: %zu) ***\n",
 		config.name, config.type, writer_pid, qn, saved_index, duration);
 
   if (config.sql_trigger_exec && !safe_action) P_trigger_exec(config.sql_trigger_exec); 
