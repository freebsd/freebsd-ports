--- src/main.c.orig	Tue Nov  2 15:29:14 2004
+++ src/main.c	Tue Nov  2 15:30:16 2004
@@ -194,20 +194,6 @@
 
 	srandom((gint)time(NULL));
 
-	/* parse gtkrc files */
-	userrc = g_strconcat(get_home_dir(), G_DIR_SEPARATOR_S, ".gtkrc-2.0",
-			     NULL);
-	gtk_rc_parse(userrc);
-	g_free(userrc);
-	userrc = g_strconcat(get_home_dir(), G_DIR_SEPARATOR_S, ".gtk",
-			     G_DIR_SEPARATOR_S, "gtkrc-2.0", NULL);
-	gtk_rc_parse(userrc);
-	g_free(userrc);
-	userrc = g_strconcat(get_rc_dir(), G_DIR_SEPARATOR_S, "gtkrc-2.0",
-			     NULL);
-	gtk_rc_parse(userrc);
-	g_free(userrc);
-
 	userrc = g_strconcat(get_rc_dir(), G_DIR_SEPARATOR_S, MENU_RC, NULL);
 	gtk_accel_map_load (userrc);
 	g_free(userrc);
