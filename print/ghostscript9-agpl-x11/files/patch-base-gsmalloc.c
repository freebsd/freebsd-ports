--- base/gsmalloc.c.orig	2015-08-22 03:09:16.838614000 +0900
+++ base/gsmalloc.c	2015-08-22 03:09:34.776354000 +0900
@@ -178,7 +178,7 @@
     } else {
         uint added = size + sizeof(gs_malloc_block_t);
 
-        if (mmem->limit - added < mmem->used)
+        if (added <= size || mmem->limit - added < mmem->used)
             set_msg("exceeded limit");
         else if ((ptr = (byte *) Memento_label(malloc(added), cname)) == 0)
             set_msg("failed");
