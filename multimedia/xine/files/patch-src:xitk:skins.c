--- src/xitk/skins.c.orig	Mon Nov 22 17:45:26 2004
+++ src/xitk/skins.c	Thu Dec 30 04:32:43 2004
@@ -1083,8 +1083,9 @@
   layer_above_video(xitk_window_get_window(xwin));
   
   if((slxs = skins_get_slx_entries(url)) != NULL) {
-    char                      *fontname    = "-*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*";
-    char                      *btnfontname = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
+    char                      *fontname    = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
+    char                      *btnfontname = "-*-*-bold-r-normal-*-12-*-*-*-*-*-*-*";
+
     int                        i;
     xitk_browser_widget_t      br;
     xitk_labelbutton_widget_t  lb;
