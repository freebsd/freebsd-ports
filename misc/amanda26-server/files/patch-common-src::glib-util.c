--- common-src/glib-util.c.orig	2008-12-01 22:17:19.000000000 +0100
+++ common-src/glib-util.c	2011-06-25 22:43:28.000000000 +0200
@@ -38,26 +38,15 @@
     if (did_glib_init) return;
     did_glib_init = TRUE;
 
-    /* Initialize glib's type system */
-    g_type_init();
-
     /* set up libcurl (this must happen before threading 
      * is initialized) */
 #ifdef HAVE_LIBCURL
 # ifdef G_THREADS_ENABLED
-    g_assert(!g_thread_supported());
+    g_assert(!g_thread_supported()); /* assert threads aren't initialized yet */
 # endif
     g_assert(curl_global_init(CURL_GLOBAL_ALL) == 0);
 #endif
 
-    /* And set up glib's threads */
-#if defined(G_THREADS_ENABLED) && !defined(G_THREADS_IMPL_NONE)
-    if (g_thread_supported()) {
-        return;
-    }
-    g_thread_init(NULL);
-#endif
-
     /* do a version check */
 #if GLIB_CHECK_VERSION(2,6,0)
     {
@@ -71,6 +60,17 @@
 	}
     }
 #endif
+
+    /* Initialize glib's type system.  On glib >= 2.24, this will initialize
+     * threads, so it must be done after curl is initialized. */
+    g_type_init();
+
+    /* And set up glib's threads */
+#if defined(G_THREADS_ENABLED) && !defined(G_THREADS_IMPL_NONE)
+    if (!g_thread_supported())
+        g_thread_init(NULL);
+#endif
+
 }
 
 typedef enum {
@@ -107,29 +107,19 @@
     return to;
 }
 
-void g_list_free_full(GList * list) {
-    GList * cur = list;
-
-    while (cur != NULL) {
-        gpointer data = cur->data;
-        amfree(data);
-        cur = g_list_next(cur);
-    }
-
-    g_list_free(list);
-}
-
-void g_slist_free_full(GSList * list) {
+#if (GLIB_MAJOR_VERSION < 2 || (GLIB_MAJOR_VERSION == 2 && GLIB_MINOR_VERSION < 28))
+void _slist_free_full(GSList * list, GDestroyNotify free_fn) {
     GSList * cur = list;
 
     while (cur != NULL) {
         gpointer data = cur->data;
-        amfree(data);
+        free_fn(data);
         cur = g_slist_next(cur);
     }
 
     g_slist_free(list);
 }
+#endif
 
 void g_queue_free_full(GQueue * queue) {
     while (!g_queue_is_empty(queue)) {
