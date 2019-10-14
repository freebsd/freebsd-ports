--- src/libutil/mem_pool.c.orig	2019-10-11 16:56:09 UTC
+++ src/libutil/mem_pool.c
@@ -111,7 +111,7 @@ pool_chain_free (struct _pool_chain *chain)
 			chain->slice_size - occupied : 0);
 }
 
-/* By default allocate 8Kb chunks of memory */
+/* By default allocate 4Kb chunks of memory */
 #define FIXED_POOL_SIZE 4096
 
 static inline struct rspamd_mempool_entry_point *
@@ -156,6 +156,7 @@ RSPAMD_DESTRUCTOR (rspamd_mempool_entries_dtor)
 	});
 
 	kh_destroy (mempool_entry, mempool_entries);
+	mempool_entries = NULL;
 }
 
 static inline struct rspamd_mempool_entry_point *
@@ -676,7 +677,7 @@ rspamd_mempool_delete (rspamd_mempool_t * pool)
 		cur = pool->pools[RSPAMD_MEMPOOL_NORMAL];
 	}
 
-	if (cur) {
+	if (cur && mempool_entries) {
 		pool->entry->elts[pool->entry->cur_elts].leftover =
 				pool_chain_free (cur);
 
