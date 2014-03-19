--- src/nemo-notebook.c.orig	2014-03-08 01:46:16.347348229 +0000
+++ src/nemo-notebook.c	2014-03-08 01:56:25.092307128 +0000
@@ -51,12 +51,6 @@
 static void nemo_notebook_remove	 (GtkContainer *container,
 					  GtkWidget *tab_widget);
 
-static const GtkTargetEntry url_drag_types[] = 
-{
-	{ NEMO_ICON_DND_GNOME_ICON_LIST_TYPE, 0, NEMO_ICON_DND_GNOME_ICON_LIST },
-	{ NEMO_ICON_DND_URI_LIST_TYPE, 0, NEMO_ICON_DND_URI_LIST },
-};
-
 enum
 {
 	TAB_CLOSE_REQUEST,
