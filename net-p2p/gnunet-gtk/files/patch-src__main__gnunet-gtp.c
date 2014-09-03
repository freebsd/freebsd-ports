--- src/main/gnunet-gtk.c.orig
+++ src/main/gnunet-gtk.c
@@ -177,7 +177,7 @@
 }
 
 
-#ifdef GDK_WINDOWING_X11
+#if defined(GDK_WINDOWING_X11) && GTK_MAJOR_VERSION >= 3
 /**
  * Start the child process for the plug.
  *
@@ -308,7 +308,7 @@
   main_window = GTK_WIDGET (get_object ("gnunet_gtk_window"));
   GNUNET_SCHEDULER_add_delayed (GNUNET_TIME_UNIT_FOREVER_REL,
 				&cleanup_task, NULL);
-#ifdef GDK_WINDOWING_X11
+#if defined(GDK_WINDOWING_X11) && GTK_MAJOR_VERSION >= 3
   plug ("gnunet_statistics_hbox",
         "gnunet-statistics-gtk",
         "GNUNET_STATISTICS_GTK_PLUG");
