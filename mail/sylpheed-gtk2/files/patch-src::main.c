--- src/main.c.orig	Sun Apr 18 17:22:45 2004
+++ src/main.c	Sun Apr 18 17:23:11 2004
@@ -194,21 +194,6 @@
 
 	srandom((gint)time(NULL));
 
-	/* parse gtkrc files */
-	userrc = g_strconcat(get_home_dir(), G_DIR_SEPARATOR_S, ".gtkrc",
-			     NULL);
-	gtk_rc_parse(userrc);
-	g_free(userrc);
-	userrc = g_strconcat(get_home_dir(), G_DIR_SEPARATOR_S, ".gtk",
-			     G_DIR_SEPARATOR_S, "gtkrc", NULL);
-	gtk_rc_parse(userrc);
-	g_free(userrc);
-	userrc = g_strconcat(get_rc_dir(), G_DIR_SEPARATOR_S, "gtkrc", NULL);
-	gtk_rc_parse(userrc);
-	g_free(userrc);
-
-	gtk_rc_parse("./gtkrc");
-
 	userrc = g_strconcat(get_rc_dir(), G_DIR_SEPARATOR_S, MENU_RC, NULL);
 	gtk_accel_map_load (userrc);
 	g_free(userrc);
