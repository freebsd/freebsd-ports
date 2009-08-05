--- plugins/elements/gstfilesrc.c.orig	2009-07-14 11:54:05.000000000 +0200
+++ plugins/elements/gstfilesrc.c	2009-08-05 09:23:45.000000000 +0200
@@ -585,8 +585,8 @@ gst_file_src_map_region (GstFileSrc * sr
 
   g_return_val_if_fail (offset >= 0, NULL);
 
-  GST_LOG_OBJECT (src, "mapping region %08llx+%08lx from file into memory",
-      offset, (gulong) size);
+  GST_LOG_OBJECT (src, "mapping region %08lx+%08lx from file into memory",
+      (gulong) offset, (gulong) size);
 
   mmapregion = mmap (NULL, size, PROT_READ, MAP_SHARED, src->fd, offset);
 
