
--- common-src/glib-util.c.orig	2010-05-20 13:19:58.000000000 -0400
+++ common-src/glib-util.c	2010-05-20 13:24:40.000000000 -0400
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


