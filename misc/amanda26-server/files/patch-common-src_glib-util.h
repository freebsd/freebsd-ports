--- common-src/glib-util.h.orig	2011-06-25 22:39:20.000000000 +0200
+++ common-src/glib-util.h	2011-06-25 22:40:39.000000000 +0200
@@ -62,10 +62,16 @@ GValue* g_value_unset_init(GValue* val, 
  * Returns its second (reset) argument.*/
 GValue* g_value_unset_copy(const GValue* from, GValue * to);
 
+/* This function is available in glib-2.28.0 and higher; for lower versions
+ * we build our own version with a different name */
+#if (GLIB_MAJOR_VERSION < 2 || (GLIB_MAJOR_VERSION == 2 && GLIB_MINOR_VERSION < 28))
+void _slist_free_full(GSList * list, GDestroyNotify free_fn);
+#else
+#define _slist_free_full(list, free_fn) g_slist_free_full((list), (free_fn))
+#endif
+
 /* These functions all take a GLib container, and call free() on all the
  * pointers in the container before free()ing the container itself. */
-void g_list_free_full(GList * list);
-void g_slist_free_full(GSList * list);
 void g_queue_free_full(GQueue * queue);
 void g_ptr_array_free_full(GPtrArray * array);
 
