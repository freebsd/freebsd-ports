--- src/splash.c.orig	Fri Oct 13 00:38:03 2000
+++ src/splash.c	Fri Oct 13 00:38:50 2000
@@ -32,7 +32,7 @@
 		gtk_signal_connect (GTK_OBJECT(WinSplash), "button_press_event", GTK_SIGNAL_FUNC (gtk_widget_destroy), NULL);
 		
 		if(cresc_pref->prefix) {
-			temp = g_strconcat (cresc_pref->prefix, "share/crescendo/cr-splash1.jpg", NULL);
+			temp = g_strconcat (CRESCENDO_DATADIR, "/cr-splash1.jpg", NULL);
 			picSplash = gnome_pixmap_new_from_file(temp);
 			gtk_container_add(GTK_CONTAINER(WinSplash),picSplash);
 			g_free(temp);
