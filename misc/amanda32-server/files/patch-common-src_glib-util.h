--- common-src/glib-util.h.orig	2013-02-07 15:57:26.000000000 +0000
+++ common-src/glib-util.h	2013-02-07 15:57:54.000000000 +0000
@@ -72,7 +72,6 @@
 
 /* These functions all take a GLib container, and call free() on all the
  * pointers in the container before free()ing the container itself. */
-void g_queue_free_full(GQueue * queue);
 void g_ptr_array_free_full(GPtrArray * array);
 
 /* g_value_compare() does what you expect. It returns TRUE if and
