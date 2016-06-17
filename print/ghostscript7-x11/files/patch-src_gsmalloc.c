--- src/gsmalloc.c.orig	2003-01-17 00:49:03 UTC
+++ src/gsmalloc.c
@@ -170,7 +170,7 @@ gs_heap_alloc_bytes(gs_memory_t * mem, u
     } else {
 	uint added = size + sizeof(gs_malloc_block_t);
 
-	if (mmem->limit - added < mmem->used)
+	if (added <= size || mmem->limit - added < mmem->used)
 	    set_msg("exceeded limit");
 	else if ((ptr = (byte *) malloc(added)) == 0)
 	    set_msg("failed");
