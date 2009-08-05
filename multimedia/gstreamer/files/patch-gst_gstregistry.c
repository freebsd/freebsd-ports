--- gst/gstregistry.c.orig	2009-07-14 11:54:05.000000000 +0200
+++ gst/gstregistry.c	2009-08-05 14:05:20.000000000 +0200
@@ -896,7 +896,7 @@ gst_registry_scan_path_level (GstRegistr
         GST_DEBUG_OBJECT (registry, "mtime %ld != %ld or size %"
             G_GINT64_FORMAT " != %" G_GINT64_FORMAT " or external dependency "
             "env_vars changed: %d or external dependencies changed: %d",
-            plugin->file_mtime, file_status.st_mtime,
+            (glong) plugin->file_mtime, (glong) file_status.st_mtime,
             (gint64) plugin->file_size, (gint64) file_status.st_size,
             env_vars_changed, deps_changed);
         gst_registry_remove_plugin (gst_registry_get_default (), plugin);
