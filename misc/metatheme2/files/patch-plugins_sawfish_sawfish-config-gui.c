--- plugins/sawfish/sawfish-config-gui.c.orig	Sun May 19 04:05:50 2002
+++ plugins/sawfish/sawfish-config-gui.c	Sun May 19 04:06:00 2002
@@ -35,7 +35,7 @@
 	GArray *files;
 	gchar **ret;
 	/* FIXME */
-	gchar *dirnames[] = { "/usr/share/sawfish/themes", "/.sawfish/themes", NULL};
+	gchar *dirnames[] = { "%%X11BASE%%/share/sawfish/themes", "/.sawfish/themes", NULL};
 	int i;
 
 	dirnames[1] = g_strconcat (g_get_home_dir (), dirnames[1], NULL);
