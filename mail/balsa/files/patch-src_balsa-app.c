--- src/balsa-app.c.orig	Fri Aug  6 17:43:17 2004
+++ src/balsa-app.c	Fri Aug  6 17:43:42 2004
@@ -652,10 +652,6 @@
     BalsaFind bf;
     gboolean is_sub_thread = libbalsa_am_i_subthread();
 
-#ifdef BALSA_USE_THREADS
-    g_assert(!g_mutex_trylock(gdk_threads_mutex));
-#endif
-
     if (is_sub_thread)
 	gdk_threads_enter();
 
