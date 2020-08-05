--- src/sql_common.c.orig	2020-05-10 13:57:54 UTC
+++ src/sql_common.c
@@ -126,8 +126,8 @@ void sql_init_global_buffers()
   lru_tail = &lru_head;
 
   Log(LOG_INFO, "INFO ( %s/%s ): cache entries=%d base cache memory=%luu bytes\n", config.name, config.type,
-        config.sql_cache_entries, ((config.sql_cache_entries * sizeof(struct db_cache)) +
-	(2 * (qq_size * sizeof(struct db_cache *)))));
+        config.sql_cache_entries, (unsigned long) ((config.sql_cache_entries * sizeof(struct db_cache)) +
+	(2 * (qq_size * sizeof(struct db_cache *)))) );
 
   pipebuf = (unsigned char *) malloc(config.buffer_size);
   sql_cache = (struct db_cache *) malloc(config.sql_cache_entries*sizeof(struct db_cache));
