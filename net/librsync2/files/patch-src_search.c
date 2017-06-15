# https://github.com/librsync/librsync/pull/59/files
--- src/search.c.orig	2015-11-29 20:43:12 UTC
+++ src/search.c
@@ -218,7 +218,7 @@ rs_search_for_block(rs_weak_sum_t weak_s
 	    r = m;
     }
 
-    if (l == r) {
+    if ((l == r) && (l <= bucket->r)) {
 	int i = sig->targets[l].i;
 	rs_block_sig_t *b = &(sig->block_sigs[i]);
 	if (weak_sum != b->weak_sum)
