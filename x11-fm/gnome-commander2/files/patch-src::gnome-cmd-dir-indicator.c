--- src/gnome-cmd-dir-indicator.c.orig	Tue Jun 22 19:55:28 2004
+++ src/gnome-cmd-dir-indicator.c	Tue Jun 22 19:56:15 2004
@@ -91,11 +91,11 @@
 	if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
 		/* left click - work out the path */
 		gchar *chTo;
+		gint i;
 		const gchar *labelText = gtk_label_get_text (GTK_LABEL (indicator->priv->label));
+		gint x = (gint)event->x;
 		chTo = malloc (strlen (labelText) + 1);
 		strcpy (chTo, labelText);
-		gint x = (gint)event->x;
-		gint i;
 		  
 		for (i = 0; i < indicator->priv->numPositions; i++) {
 			if (x < indicator->priv->slashPixelPosition[i]) {
