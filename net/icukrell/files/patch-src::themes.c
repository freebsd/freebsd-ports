--- src/themes.c.orig	Sun May  6 18:02:50 2001
+++ src/themes.c	Mon Jul  2 22:49:07 2001
@@ -43,6 +43,8 @@
 #endif
 	make_file_name("gnomeicu-offline.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         offline_pixmap = gdk_imlib_copy_image(im);
         offline_bitmap = gdk_imlib_copy_mask(im);
@@ -53,6 +55,8 @@
 #endif
 	make_file_name("gnomeicu-online.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         online_pixmap = gdk_imlib_copy_image(im);
         online_bitmap = gdk_imlib_copy_mask(im);
@@ -63,6 +67,8 @@
 #endif
 	make_file_name("gnomeicu-inv.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         inv_pixmap = gdk_imlib_copy_image(im);
         inv_bitmap = gdk_imlib_copy_mask(im);
@@ -73,6 +79,8 @@
 #endif
 	make_file_name("gnomeicu-na.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         na_pixmap = gdk_imlib_copy_image(im);
         na_bitmap = gdk_imlib_copy_mask(im);
@@ -83,6 +91,8 @@
 #endif
 	make_file_name("gnomeicu-ffc.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         chat_pixmap = gdk_imlib_copy_image(im);
         chat_bitmap = gdk_imlib_copy_mask(im);
@@ -93,6 +103,8 @@
 #endif
 	make_file_name("gnomeicu-occ.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         occ_pixmap = gdk_imlib_copy_image(im);
         occ_bitmap = gdk_imlib_copy_mask(im);
@@ -103,6 +115,8 @@
 #endif
 	make_file_name("gnomeicu-away.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         away_pixmap = gdk_imlib_copy_image(im);
         away_bitmap = gdk_imlib_copy_mask(im);
@@ -113,6 +127,8 @@
 #endif
 	make_file_name("gnomeicu-dnd.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
         dnd_pixmap = gdk_imlib_copy_image(im);
         dnd_bitmap = gdk_imlib_copy_mask(im);
@@ -123,6 +139,8 @@
 #endif
 	make_file_name("gnomeicu-message.png");
 	im = gdk_imlib_load_image(full_file);
+	if (im == NULL) 
+	  return FALSE;
 	gdk_imlib_render(im, im->rgb_width, im->rgb_height);
 	message_pixmap = gdk_imlib_copy_image(im);
         message_bitmap = gdk_imlib_copy_mask(im);
