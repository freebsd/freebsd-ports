--- capplet/gnome-pilot-cdialog.c.orig	Mon Aug  2 20:12:19 2004
+++ capplet/gnome-pilot-cdialog.c	Mon Aug  2 20:12:25 2004
@@ -123,6 +123,7 @@
 	gnome_dialog_close_hides (GNOME_DIALOG (priv->dialog), TRUE);
 	
  error:
+	return;
 }
 
 
