--- src/gsalloc.c.orig	2013-04-30 11:14:17.000000000 +0900
+++ src/gsalloc.c	2013-04-30 11:14:34.000000000 +0900
@@ -195,7 +195,7 @@
     iimem->large_size = ((chunk_size / 4) & -obj_align_mod) + 1;
     iimem->is_controlled = false;
     iimem->gc_status.vm_threshold = chunk_size * 3L;
-    iimem->gc_status.max_vm = max_long;
+    iimem->gc_status.max_vm = 0x7fffffff;
     iimem->gc_status.psignal = NULL;
     iimem->gc_status.signal_value = 0;
     iimem->gc_status.enabled = false;
