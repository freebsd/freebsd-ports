--- gdl/gdl-icons.c.orig	Tue May 24 16:37:14 2005
+++ gdl/gdl-icons.c	Tue May 24 16:37:38 2005
@@ -202,12 +202,13 @@
 {
 	GdkPixbuf *pixbuf;
 	char *icon_name;
+	GdlIconsPrivate *priv;
 
 	g_return_val_if_fail (icons != NULL, NULL);
 	g_return_val_if_fail (GDL_IS_ICONS (icons), NULL);
 	g_return_val_if_fail (mime_type != NULL, NULL);
 
-	GdlIconsPrivate *priv = GDL_ICONS_GET_PRIVATE (icons);
+	priv = GDL_ICONS_GET_PRIVATE (icons);
 
 	pixbuf = g_hash_table_lookup (priv->icons, mime_type);
 	if (pixbuf != NULL) {
