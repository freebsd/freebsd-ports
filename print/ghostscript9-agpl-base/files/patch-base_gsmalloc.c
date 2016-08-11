--- base/gsmalloc.c.orig	2015-03-30 08:21:24 UTC
+++ base/gsmalloc.c
@@ -178,7 +178,7 @@ gs_heap_alloc_bytes(gs_memory_t * mem, u
     } else {
         uint added = size + sizeof(gs_malloc_block_t);
 
-        if (mmem->limit - added < mmem->used)
+        if (added <= size || mmem->limit - added < mmem->used)
             set_msg("exceeded limit");
         else if ((ptr = (byte *) Memento_label(malloc(added), cname)) == 0)
             set_msg("failed");
