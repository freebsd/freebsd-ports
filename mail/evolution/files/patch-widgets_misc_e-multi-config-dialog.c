--- widgets/misc/e-multi-config-dialog.c.orig	Tue Nov 23 15:53:34 2004
+++ widgets/misc/e-multi-config-dialog.c	Tue Nov 23 15:54:02 2004
@@ -396,6 +396,7 @@
 {
 	EMultiConfigDialogPrivate *priv;
 	AtkObject *a11y;
+	AtkObject *a11yPage;
 	gint page_no;
 
 	g_return_if_fail (E_IS_MULTI_CONFIG_DIALOG (dialog));
@@ -418,7 +419,7 @@
 				  NULL);
 
 	a11y = gtk_widget_get_accessible (GTK_WIDGET(priv->notebook));
-	AtkObject *a11yPage = atk_object_ref_accessible_child (a11y, page_no);
+	a11yPage = atk_object_ref_accessible_child (a11y, page_no);
 	if (a11yPage != NULL) {
 		if (atk_object_get_role (a11yPage) == ATK_ROLE_PAGE_TAB)
 			atk_object_set_name (a11yPage, title);
