--- common-src/glib-util.c.orig	2013-02-07 15:57:30.000000000 +0000
+++ common-src/glib-util.c	2013-02-07 15:57:50.000000000 +0000
@@ -120,15 +120,6 @@
 }
 #endif
 
-void g_queue_free_full(GQueue * queue) {
-    while (!g_queue_is_empty(queue)) {
-        gpointer data;
-        data = g_queue_pop_head(queue);
-        amfree(data);
-    }
-    g_queue_free(queue);
-}
-
 void g_ptr_array_free_full(GPtrArray * array) {
     size_t i;
 
