--- src/sql_common.c.orig	2020-05-10 13:57:54 UTC
+++ src/sql_common.c
@@ -45,8 +45,8 @@ unsigned char *pipebuf;
 struct db_cache *sql_cache;
 struct db_cache **sql_queries_queue, **sql_pending_queries_queue;
 struct db_cache *collision_queue;
-int cq_ptr, qq_ptr, qq_size, pp_size, pb_size, pn_size, pm_size, pt_size;
-int pc_size, dbc_size, cq_size, pqq_ptr;
+int cq_ptr, qq_size;
+int cq_size;
 struct db_cache lru_head, *lru_tail;
 struct frags where[N_PRIMITIVES+2];
 struct frags values[N_PRIMITIVES+2];
@@ -60,8 +60,7 @@ time_t glob_committed_basetime; /* last resort for sig
 int glob_dyn_table, glob_dyn_table_time_only; /* last resort for signal handling */
 int glob_timeslot; /* last resort for sql handlers */
 
-struct sqlfunc_cb_registry sqlfunc_cbr; 
-void (*insert_func)(struct primitives_ptrs *, struct insert_data *);
+struct sqlfunc_cb_registry sqlfunc_cbr;
 struct DBdesc p;
 struct DBdesc b;
 struct BE_descs bed;
@@ -126,8 +125,8 @@ void sql_init_global_buffers()
   lru_tail = &lru_head;
 
   Log(LOG_INFO, "INFO ( %s/%s ): cache entries=%d base cache memory=%luu bytes\n", config.name, config.type,
-        config.sql_cache_entries, ((config.sql_cache_entries * sizeof(struct db_cache)) +
-	(2 * (qq_size * sizeof(struct db_cache *)))));
+        config.sql_cache_entries, (unsigned long) ((config.sql_cache_entries * sizeof(struct db_cache)) +
+	(2 * (qq_size * sizeof(struct db_cache *)))) );
 
   pipebuf = (unsigned char *) malloc(config.buffer_size);
   sql_cache = (struct db_cache *) malloc(config.sql_cache_entries*sizeof(struct db_cache));
