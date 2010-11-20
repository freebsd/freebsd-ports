--- extensions/adblock/ephy-adblock-extension.c.orig	2010-08-19 08:54:27.000000000 +0200
+++ extensions/adblock/ephy-adblock-extension.c	2010-08-19 08:54:54.000000000 +0200
@@ -385,8 +385,8 @@ ephy_adblock_extension_edit_cb (GtkActio
 }
 
 static void
-switch_page_cb (GtkNotebook *notebook,
-		GtkNotebookPage *page,
+switch_page_cb (GtkWidget *notebook,
+		GtkWidget *page,
 		guint page_num,
 		EphyWindow *window)
 {
