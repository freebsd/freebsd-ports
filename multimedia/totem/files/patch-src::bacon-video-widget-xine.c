--- src/bacon-video-widget-xine.c.orig	Wed Mar  9 18:03:18 2005
+++ src/bacon-video-widget-xine.c	Wed Mar  9 18:05:59 2005
@@ -2504,10 +2504,8 @@
 
 	/* And we try and create symlinks from /usr/lib/win32 to
 	 * the local user path */
-	totem_create_symlinks ("/usr/lib/win32", path);
-	totem_create_symlinks ("/usr/lib/RealPlayer9/Codecs/", path);
-	totem_create_symlinks ("/usr/lib/RealPlayer9/users/Real/Codecs/", path);
-	totem_create_symlinks ("/usr/lib/RealPlayer8/Codecs", path);
+	totem_create_symlinks ("@LOCALBASE@/lib/win32", path);
+	totem_create_symlinks ("@LOCALBASE@/lib/RealPlayer/codecs", path);
 
 	g_free (bvw->priv->codecs_path);
 	bvw->priv->codecs_path = g_strdup (path);
