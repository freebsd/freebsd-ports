--- src/main.c.orig	Sat Jul  3 01:52:00 2004
+++ src/main.c	Sat Jul  3 01:52:35 2004
@@ -194,22 +194,6 @@
 
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
-	gtk_rc_parse("./gtkrc-2.0");
-
 	userrc = g_strconcat(get_rc_dir(), G_DIR_SEPARATOR_S, MENU_RC, NULL);
 	gtk_accel_map_load (userrc);
 	g_free(userrc);
