--- src/sound_handling.cpp.orig	Thu Jan 27 14:47:01 2005
+++ src/sound_handling.cpp	Thu Jan 27 14:57:07 2005
@@ -466,7 +466,7 @@
       dialog =
 	gtk_dialog_new_with_buttons ("Audio test running...",
 				     GTK_WINDOW (gw->druid_window),
-				     (enum GtkDialogFlags) (GTK_DIALOG_DESTROY_WITH_PARENT),
+				     (GtkDialogFlags) (GTK_DIALOG_DESTROY_WITH_PARENT),
 				     GTK_STOCK_OK,
 				     GTK_RESPONSE_ACCEPT,
 				     NULL);
