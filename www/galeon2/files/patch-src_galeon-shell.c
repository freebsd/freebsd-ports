--- src/galeon-shell.c.orig	Tue Oct 28 01:07:00 2003
+++ src/galeon-shell.c	Tue Oct 28 01:09:34 2003
@@ -186,6 +186,7 @@
 	if (gs->priv->automation_factory == NULL)
 	{
 		GtkWidget *dialog;
+		char *text;
 
 		dialog = hig_alert_new (NULL,
 					GTK_DIALOG_MODAL,
@@ -195,7 +196,7 @@
 					GTK_STOCK_OK,
 					GTK_RESPONSE_OK,
 					NULL);
-		char * text = g_strdup_printf (_("Bonobo couldn't locate the file %s."),
+		text = g_strdup_printf (_("Bonobo couldn't locate the file %s."),
 					       "<tt>\"GNOME_Galeon_Automation.server\"</tt>");
 		hig_alert_set_secondary_printf (HIG_ALERT (dialog), "%s\n\n%s", text,
 			      _("Usually this is an indication of an incomplete installation. "
