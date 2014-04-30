--- ./src/gnome_ui.c.orig	2008-06-12 22:48:03.000000000 +0200
+++ ./src/gnome_ui.c	2014-04-30 22:44:15.000000000 +0200
@@ -1679,7 +1679,7 @@
 {
 #define DEBUGFUNCTION "xvc_init_pre()"
     g_thread_init (NULL);
-    gdk_threads_init ();
+    /*gdk_threads_init ();*/
 
     gtk_init (&argc, &argv);
     return TRUE;
