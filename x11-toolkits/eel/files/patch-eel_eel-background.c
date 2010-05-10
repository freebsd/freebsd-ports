--- eel/eel-background.c.orig	2009-03-02 11:21:55.000000000 -0500
+++ eel/eel-background.c	2010-01-24 01:08:43.000000000 -0500
@@ -368,7 +368,7 @@ eel_background_ensure_realized (EelBackg
 
 	set_image_properties (background);
 
-	background->details->background_changes_with_size = gnome_bg_changes_with_size (background->details->bg);
+	background->details->background_changes_with_size = gnome_bg_has_multiple_sizes (background->details->bg);
 	background->details->background_pixmap = gnome_bg_create_pixmap (background->details->bg,
 									 window,
 									 entire_width, entire_height,
@@ -747,7 +747,7 @@ eel_background_set_up_widget (EelBackgro
         }
 	
 	background->details->background_changes_with_size =
-		gnome_bg_changes_with_size (background->details->bg);
+		gnome_bg_has_multiple_sizes (background->details->bg);
 	
 	if (background->details->is_desktop && !in_fade) {
 		set_root_pixmap (background, window);
@@ -1000,7 +1000,7 @@ eel_get_widget_background (GtkWidget *wi
 gboolean
 eel_background_is_dark (EelBackground *background)
 {
-	return gnome_bg_is_dark (background->details->bg);
+	return gnome_bg_is_dark (background->details->bg, background->details->background_entire_width, background->details->background_entire_height);
 }
    
 /* handle dropped colors */
