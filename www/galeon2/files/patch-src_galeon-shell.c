--- src/galeon-shell.c.orig	Mon Oct 13 17:56:13 2003
+++ src/galeon-shell.c	Tue Nov  4 23:07:54 2003
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
@@ -283,8 +284,6 @@
 	gb_bookmark_set_check_save (gs->priv->bookmark_set);
 	g_object_unref (G_OBJECT (gs->priv->bookmark_set));
 	
-        g_free (gs->priv);
-
         G_OBJECT_CLASS (parent_class)->finalize (object);
 
 #ifdef DEBUG_MARCO
@@ -295,6 +294,8 @@
 	{
 		bonobo_object_unref (gs->priv->automation_factory);
 	}
+
+        g_free (gs->priv);
 	
 	bonobo_main_quit ();
 
