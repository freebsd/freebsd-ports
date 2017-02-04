--- src/main/gnunet-gtk.c.orig	2014-04-08 07:44:56 UTC
+++ src/main/gnunet-gtk.c
@@ -177,7 +177,7 @@ gnunet_gtk_quit_cb (GObject * object,
 }
 
 
-#ifdef GDK_WINDOWING_X11
+#if defined(GDK_WINDOWING_X11) && GTK_MAJOR_VERSION >= 3
 /**
  * Start the child process for the plug.
  *
@@ -308,7 +308,7 @@ run (void *cls,
   main_window = GTK_WIDGET (get_object ("gnunet_gtk_window"));
   GNUNET_SCHEDULER_add_delayed (GNUNET_TIME_UNIT_FOREVER_REL,
 				&cleanup_task, NULL);
-#ifdef GDK_WINDOWING_X11
+#if defined(GDK_WINDOWING_X11) && GTK_MAJOR_VERSION >= 3
   plug ("gnunet_statistics_hbox",
         "gnunet-statistics-gtk",
         "GNUNET_STATISTICS_GTK_PLUG");
