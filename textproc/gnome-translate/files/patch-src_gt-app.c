--- src/gt-app.c.orig	Fri Jan 28 13:31:53 2005
+++ src/gt-app.c	Mon May  1 19:58:44 2006
@@ -1168,8 +1168,7 @@
 						     GTK_MESSAGE_WARNING,
 						     GTK_BUTTONS_YES_NO,
 						     _("Overwrite file?"),
-						     secondary,
-						     NULL);
+						     secondary);
 	  g_free(secondary);
 
 	  gtk_dialog_set_default_response(GTK_DIALOG(confirmation_dialog), GTK_RESPONSE_NO); /* safe default */
