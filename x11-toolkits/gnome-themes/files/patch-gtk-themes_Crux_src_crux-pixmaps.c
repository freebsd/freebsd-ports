--- gtk-themes/Crux/src/crux-pixmaps.c.orig	Thu Oct 16 21:01:59 2003
+++ gtk-themes/Crux/src/crux-pixmaps.c	Thu Oct 16 21:02:17 2003
@@ -340,9 +340,10 @@
     {
 	GdkPixbuf *pixbuf;
 	size_t len = strlen (*path) + strlen (file) + 2;
-	char *buf = alloca (len);
+	char *buf = g_malloc (len);
 	sprintf (buf, "%s/%s", *path, file);
 	pixbuf = gdk_pixbuf_new_from_file (buf, NULL);
+	g_free (buf);
 	if (pixbuf != 0)
 	    return pixbuf;
 	path++;
