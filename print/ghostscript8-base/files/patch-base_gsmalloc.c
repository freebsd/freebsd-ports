--- base/gsmalloc.c.orig	2009-08-18 20:41:17 UTC
+++ base/gsmalloc.c
@@ -174,7 +174,7 @@ gs_heap_alloc_bytes(gs_memory_t * mem, u
     } else {
 	uint added = size + sizeof(gs_malloc_block_t);
 
-	if (mmem->limit - added < mmem->used)
+	if (added <= size || mmem->limit - added < mmem->used)
 	    set_msg("exceeded limit");
 	else if ((ptr = (byte *) malloc(added)) == 0)
 	    set_msg("failed");
