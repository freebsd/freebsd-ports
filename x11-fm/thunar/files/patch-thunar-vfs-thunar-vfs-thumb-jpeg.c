--- thunar-vfs/thunar-vfs-thumb-jpeg.c.orig	Mon Jan 22 09:54:27 2007
+++ thunar-vfs/thunar-vfs-thumb-jpeg.c	Mon Jan 22 12:59:03 2007
@@ -306,22 +306,13 @@
   guint         data_len;
 
   guint         thumb_compression;
-  union
-  {
-    struct /* thumbnail JPEG */
-    {
       guint     thumb_jpeg_length;
       guint     thumb_jpeg_offset;
-    };
-    struct /* thumbnail TIFF */
-    {
       guint     thumb_tiff_length;
       guint     thumb_tiff_offset;
       guint     thumb_tiff_interp;
       guint     thumb_tiff_height;
       guint     thumb_tiff_width;
-    };
-  };
 
   gboolean      big_endian;
 } TvtjExif;
