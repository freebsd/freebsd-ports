--- libgnomeui/gnome-app.c.orig	Sat Apr 19 16:42:12 2003
+++ libgnomeui/gnome-app.c	Sat Apr 19 16:42:21 2003
@@ -194,7 +194,7 @@
 static void
 gnome_app_instance_init (GnomeApp *app)
 {
-	const char *icons;
+	const char *icons = NULL;
 		
 	app->_priv = NULL;
 	/* XXX: when there is some private stuff enable this
