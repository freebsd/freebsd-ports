--- src/main.c.orig	2013-11-23 23:59:43.000000000 +0100
+++ src/main.c	2013-11-24 00:00:28.000000000 +0100
@@ -58,6 +58,7 @@
 
   /* start gdk threads. */
   gdk_threads_init ();
+  gdk_threads_enter();
 
   /* lock and start gtk. */
   gtk_init (&argc, &argv);
@@ -71,6 +72,8 @@
   /* punt control to the manager. */
   ggn_manager_main (manager, argc, argv);
 
+  gdk_threads_leave();
+
   /* exit the application. */
   return 0;
 }
