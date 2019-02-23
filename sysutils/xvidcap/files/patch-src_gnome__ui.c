--- src/gnome_ui.c.orig	2008-06-12 20:48:03 UTC
+++ src/gnome_ui.c
@@ -1679,7 +1679,7 @@ xvc_init_pre (int argc, char **argv)
 {
 #define DEBUGFUNCTION "xvc_init_pre()"
     g_thread_init (NULL);
-    gdk_threads_init ();
+    /*gdk_threads_init ();*/
 
     gtk_init (&argc, &argv);
     return TRUE;
