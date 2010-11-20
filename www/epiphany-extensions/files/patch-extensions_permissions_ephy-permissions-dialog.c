--- extensions/permissions/ephy-permissions-dialog.c.orig	2010-08-19 09:05:33.000000000 +0200
+++ extensions/permissions/ephy-permissions-dialog.c	2010-08-19 09:05:58.000000000 +0200
@@ -56,7 +56,7 @@ struct EphyPermissionsDialogPrivate
 {
 	EphyPermissionManager *manager;
 	GList *tabs;
-	GtkNotebook *notebook;
+	GtkWidget *notebook;
 	GtkSizeGroup *buttons_size_group;
 };
 
@@ -219,8 +219,8 @@ fill_tab (DialogTab *tab)
 }
 
 static void
-sync_notebook_tab (GtkNotebook *notebook,
-		   GtkNotebookPage *page,
+sync_notebook_tab (GtkWidget *notebook,
+		   GtkWidget *page,
 		   int page_num,
 		   EphyPermissionsDialog *dialog)
 {
