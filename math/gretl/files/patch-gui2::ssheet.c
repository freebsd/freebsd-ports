--- gui2/ssheet.c.orig	Thu Nov  6 23:46:45 2003
+++ gui2/ssheet.c	Thu Dec 25 17:33:04 2003
@@ -822,13 +822,13 @@
 {   
     GdkModifierType mods; 
     gint ret = FALSE;
+    GdkEventButton *bevent = (GdkEventButton *) event;
 
     if (event->type != GDK_BUTTON_PRESS) {
 	return FALSE;
     }
 
     gdk_window_get_pointer(view->window, NULL, NULL, &mods);
-    GdkEventButton *bevent = (GdkEventButton *) event;
 
     if (mods & GDK_BUTTON3_MASK) {
 	gtk_menu_popup (GTK_MENU(sheet->popup), NULL, NULL, NULL, NULL,
