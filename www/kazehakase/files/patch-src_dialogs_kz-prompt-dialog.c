--- src/dialogs/kz-prompt-dialog.c.orig	Wed Aug 31 19:12:53 2005
+++ src/dialogs/kz-prompt-dialog.c	Wed Aug 31 19:13:46 2005
@@ -331,12 +331,13 @@
 	}
 	else 
 	{
+		GtkWidget* okButton;
 		// Create standard ok and cancel buttons
 		if (widgetFlags & INCLUDE_CANCEL)
 			gtk_dialog_add_button(GTK_DIALOG(prompt), GTK_STOCK_CANCEL,
 					GTK_RESPONSE_CANCEL);
 
-		GtkWidget* okButton = gtk_dialog_add_button(GTK_DIALOG(prompt),
+		okButton = gtk_dialog_add_button(GTK_DIALOG(prompt),
 				GTK_STOCK_OK,
 				GTK_RESPONSE_ACCEPT);
 		gtk_widget_grab_default(okButton);
