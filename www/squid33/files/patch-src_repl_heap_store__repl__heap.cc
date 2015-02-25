--- src/repl/heap/store_repl_heap.cc.orig	2014-08-27 14:16:59 UTC
+++ src/repl/heap/store_repl_heap.cc
@@ -221,7 +221,7 @@ heap_purgeNext(RemovalPurgeWalker * walk
 
 try_again:
 
-    if (!heap_nodes(heap->theHeap) > 0)
+    if (heap_nodes(heap->theHeap) <= 0)
         return NULL;		/* done */
 
     age = heap_peepminkey(heap->theHeap);
