--- extensions/adblock/adblock-ui.c.orig	2010-08-19 08:56:01.000000000 +0200
+++ extensions/adblock/adblock-ui.c	2010-08-19 08:56:39.000000000 +0200
@@ -65,7 +65,7 @@
 struct _AdblockUIPrivate
 {
 	GtkWidget *dialog;
-	GtkNotebook *notebook;
+	GtkWidget *notebook;
 
 	/* Pages */
 	InfoPage *pages[LAST_PAGE];
@@ -347,8 +347,8 @@
 }
 
 static void
-adblock_ui_switch_page (GtkNotebook *notebook,
-			GtkNotebookPage *page,
+adblock_ui_switch_page (GtkWidget *notebook,
+			GtkWidget *page,
 			guint page_num,
 			AdblockUI *dialog)
 {
