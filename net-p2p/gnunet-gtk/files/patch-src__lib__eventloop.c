--- src/lib/eventloop.c.orig
+++ src/lib/eventloop.c
@@ -181,7 +181,7 @@
 GNUNET_GTK_plug_me (const char *env_name,
                     GtkWidget *main_window)
 {
-#ifdef GDK_WINDOWING_X11
+#if defined(GDK_WINDOWING_X11) && GTK_MAJOR_VERSION >= 3
   const char *plugid;
   GtkWidget *plug;
   GtkWidget *child;
