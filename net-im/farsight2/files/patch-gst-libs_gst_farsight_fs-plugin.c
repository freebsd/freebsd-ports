--- gst-libs/gst/farsight/fs-plugin.c.orig	2009-02-27 23:42:55.000000000 -0500
+++ gst-libs/gst/farsight/fs-plugin.c	2009-02-27 23:43:19.000000000 -0500
@@ -363,7 +363,7 @@ fs_plugin_list_available (const gchar *t
     if (!dir)
     {
       GST_WARNING ("Could not open path %s to look for plugins: %s",
-          search_path, error ? error->message : "Unknown error");
+          *search_path, error ? error->message : "Unknown error");
       g_clear_error (&error);
       continue;
     }
