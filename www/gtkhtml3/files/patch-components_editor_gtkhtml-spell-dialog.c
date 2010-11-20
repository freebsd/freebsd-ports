--- components/editor/gtkhtml-spell-dialog.c.orig	2010-09-19 17:57:00.000000000 +0000
+++ components/editor/gtkhtml-spell-dialog.c	2010-09-19 17:57:41.000000000 +0000
@@ -443,7 +443,9 @@ spell_dialog_init (GtkhtmlSpellDialog *d
 
 	gtk_dialog_add_button (
 		GTK_DIALOG (dialog), GTK_STOCK_CLOSE, GTK_RESPONSE_CLOSE);
-	gtk_dialog_set_has_separator (GTK_DIALOG (dialog), FALSE);
+#if !GTK_CHECK_VERSION(2,90,7)
+	g_object_set (dialog, "has-separator", FALSE, NULL);
+#endif
 	gtk_window_set_title (GTK_WINDOW (dialog), _("Spell Checker"));
 	gtk_container_set_border_width (GTK_CONTAINER (dialog), 5);
 
