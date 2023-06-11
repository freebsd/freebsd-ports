--- src/heap.c.orig	2023-06-11 18:59:24 UTC
+++ src/heap.c
@@ -34,7 +34,7 @@
 static heap_cell_t* pool_alloc(heap_t*);
 static void pool_swipe(heap_t*);
 /******************************************************************************/
-heap_t* heap_create()
+heap_t* heap_create(void)
 {
     heap_t* heap = calloc(1, sizeof(heap_t));
     if (!heap) {
