--- libcsv.c.orig	2012-12-28 22:50:44 UTC
+++ libcsv.c
@@ -259,6 +259,15 @@ csv_set_blk_size(struct csv_parser *p, s
 }
 
 size_t
+csv_get_blk_size(struct csv_parser *p)
+{
+  /* Get the block size used to increment buffer size */
+  if (p)
+    return p->blk_size;
+  return 0;
+}
+
+size_t
 csv_get_buffer_size(struct csv_parser *p)
 {
   /* Get the size of the entry buffer */
