--- plugins/gtk-2/gtk-config-gui.c.orig	Sun May 19 03:58:52 2002
+++ plugins/gtk-2/gtk-config-gui.c	Sun May 19 03:59:16 2002
@@ -48,7 +48,7 @@
 	GArray *files;
 	gchar **ret;
 	/* FIXME */
-	gchar *dirnames[] = { "/usr/share/themes", "/.themes", NULL};
+	gchar *dirnames[] = { "%%X11BASE%%/share/themes", "/.themes", NULL};
 	int i;
 
 	dirnames[1] = g_strconcat (g_get_home_dir (), dirnames[1], NULL);
