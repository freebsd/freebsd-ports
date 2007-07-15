--- src/xitk/skins.c.orig	Fri Mar 30 08:51:34 2007
+++ src/xitk/skins.c	Sun Jul 15 19:22:31 2007
@@ -1050,8 +1050,8 @@
   layer_above_video(xitk_window_get_window(xwin));
   
   if((slxs = skins_get_slx_entries(url)) != NULL) {
-    char                      *br_fontname = "-misc-fixed-medium-r-normal-*-10-*-*-*-*-*-*-*";
-    char                      *btnfontname = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
+    char                      *br_fontname = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
+    char                      *btnfontname = "-*-*-bold-r-*-*-12-*-*-*-*-*-*-*";
     int                        i;
     xitk_browser_widget_t      br;
     xitk_labelbutton_widget_t  lb;
