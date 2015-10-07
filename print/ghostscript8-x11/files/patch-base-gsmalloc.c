--- base/gsmalloc.c.orig	2015-07-24 09:52:39.718916000 +0900
+++ base/gsmalloc.c	2015-07-24 09:54:31.761202000 +0900
@@ -174,7 +174,7 @@
     } else {
 	uint added = size + sizeof(gs_malloc_block_t);
 
-	if (mmem->limit - added < mmem->used)
+	if (added <= size || mmem->limit - added < mmem->used)
 	    set_msg("exceeded limit");
 	else if ((ptr = (byte *) malloc(added)) == 0)
 	    set_msg("failed");
