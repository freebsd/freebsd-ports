--- src/libxosd/xosd.c.orig	Sun Jul  4 15:29:06 2004
+++ src/libxosd/xosd.c	Tue Jul 13 22:05:03 2004
@@ -272,7 +272,7 @@
 {
   int x = 10;
   int y = osd->line_height * line;
-  int i;
+  int i, draw_line_bitmap;
   xosd_line *l = &osd->lines[line];
   assert(osd);
   FUNCTION_START;
@@ -352,7 +352,7 @@
 
     if (osd->outline_offset) {
       XSetForeground(osd->display, osd->gc, osd->outline_pixel);
-      int draw_line_bitmap = !(osd->fill_mask & FILL_OUTLINE);
+      draw_line_bitmap = !(osd->fill_mask & FILL_OUTLINE);
 
       for (i = 1; i <= osd->outline_offset; i++) {
         draw_with_mask(osd, l, x + i, y, i - osd->extent->y,
@@ -432,7 +432,7 @@
   FUNCTION_START;
   DEBUG("event thread started");
   assert(osd);
-  usleep(500);
+  usleep(100000);
 
   while (!osd->done) {
     // DEBUG("checking window event");
