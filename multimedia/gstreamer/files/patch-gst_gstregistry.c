--- gst/gstregistry.c.orig	2010-01-20 02:48:56.000000000 +0100
+++ gst/gstregistry.c	2010-02-11 10:46:09.000000000 +0100
@@ -1163,7 +1163,7 @@ gst_registry_scan_path_level (GstRegistr
             G_GINT64_FORMAT " != %" G_GINT64_FORMAT " or external dependency "
             "env_vars changed: %d or external dependencies changed: %d"
             " or old path %s != new path %s",
-            plugin->file_mtime, file_status.st_mtime,
+            (glong) plugin->file_mtime, (glong) file_status.st_mtime,
             (gint64) plugin->file_size, (gint64) file_status.st_size,
             env_vars_changed, deps_changed, plugin->filename, filename);
         gst_registry_remove_plugin (context->registry, plugin);
