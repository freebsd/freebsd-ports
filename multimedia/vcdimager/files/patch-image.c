--- lib/image.c.orig	Sat Jun 26 14:47:53 2004
+++ lib/image.c	Sat Jun 26 14:48:01 2004
@@ -76,7 +76,7 @@
 }
 
 int
-vcd_image_sink_write (VcdImageSink *obj, void *buf, uint32_t lsn)
+vcd_image_sink_write (VcdImageSink *obj, void *buf, lsn_t lsn)
 {
   vcd_assert (obj != NULL);
 
