--- src/gsalloc.c.orig	2003-01-17 00:49:02 UTC
+++ src/gsalloc.c
@@ -195,7 +195,7 @@ ialloc_alloc_state(gs_raw_memory_t * par
     iimem->large_size = ((chunk_size / 4) & -obj_align_mod) + 1;
     iimem->is_controlled = false;
     iimem->gc_status.vm_threshold = chunk_size * 3L;
-    iimem->gc_status.max_vm = max_long;
+    iimem->gc_status.max_vm = 0x7fffffff;
     iimem->gc_status.psignal = NULL;
     iimem->gc_status.signal_value = 0;
     iimem->gc_status.enabled = false;
