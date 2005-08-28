--- gkrelltop.c.orig	Thu Aug  4 21:08:58 2005
+++ gkrelltop.c	Thu Aug  4 21:09:34 2005
@@ -324,7 +324,8 @@
     TextStyle *ts, *ts_alt;
     gint y;
     gint i;
-
+    GkrellmPiximage *krell_image = NULL;
+    
     /* See comments about first create in demo2.c
      */
     if (first_create)
@@ -335,7 +336,6 @@
     ts = gkrellm_meter_textstyle(style_id); //smaller font e brighter col 
     ts_alt = gkrellm_meter_alt_textstyle(style_id); //smaller font e brighter col 
 
-    GkrellmPiximage *krell_image = NULL;
     //krell_image = gkrellm_krell_meter_piximage(style_id);
     gkrellm_load_piximage("krell_panel1", krell_panel1_xpm, &krell_image, STYLE_NAME);
 /*
