--- src/gnomesu-auth-dialog.c.orig	2005-05-17 17:23:20.000000000 +0200
+++ src/gnomesu-auth-dialog.c	2010-11-22 19:23:27.000000000 +0100
@@ -212,7 +212,7 @@
 	gtk_dialog_add_action_widget (dialog, button, GTK_RESPONSE_CANCEL);
 
 	button = create_stock_button (GTK_STOCK_OK, _("C_ontinue"));
-	GTK_WIDGET_SET_FLAGS (button, GTK_HAS_DEFAULT | GTK_CAN_DEFAULT);
+	gtk_widget_set_can_default(button, TRUE);
 	gtk_widget_show (button);
 	gtk_dialog_add_action_widget (dialog, button, GTK_RESPONSE_OK);
 	gtk_widget_grab_default (button);
