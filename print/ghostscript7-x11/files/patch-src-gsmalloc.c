--- src/gsmalloc.c.orig	2015-07-24 09:55:54.032137000 +0900
+++ src/gsmalloc.c	2015-07-24 09:57:15.070246000 +0900
@@ -170,7 +170,7 @@
     } else {
 	uint added = size + sizeof(gs_malloc_block_t);
 
-	if (mmem->limit - added < mmem->used)
+	if (added <= size || mmem->limit - added < mmem->used)
 	    set_msg("exceeded limit");
 	else if ((ptr = (byte *) malloc(added)) == 0)
 	    set_msg("failed");
