--- Image.cc.orig	Sun Aug 15 07:43:55 1999
+++ Image.cc	Sat Aug  4 20:52:40 2001
@@ -50,6 +50,17 @@
 BImage::BImage(BImageControl *c, unsigned int w, unsigned int h) {
   control = c;
 
+  colors = NULL;
+  red    = NULL;
+  green  = NULL;
+  blue   = NULL;
+  tr     = NULL;
+  tg     = NULL;
+  tb     = NULL;
+
+  from.allocated = 0;
+  to.allocated   = 0;
+
   width = ((signed) w > 0) ? w : 1;
   height = ((signed) h > 0) ? h : 1;
 
@@ -843,7 +854,14 @@
   window = blackbox->getRootWindow();
   screen_number = blackbox->getScreenNumber();
 
-  colors = 0;
+  colors = NULL;
+  red_err = NULL;
+  green_err = NULL;
+  blue_err = NULL;
+  next_red_err = NULL;
+  next_green_err = NULL;
+  next_blue_err = NULL;
+  cache = NULL;
   colors_per_channel = ncolors = 0;
   
   int count;
