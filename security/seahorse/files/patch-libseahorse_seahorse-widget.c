--- libseahorse/seahorse-widget.c.orig	Mon Dec 13 23:49:49 2004
+++ libseahorse/seahorse-widget.c	Mon Dec 13 23:49:57 2004
@@ -197,7 +197,7 @@
 {
 	//error check help
 	if (g_str_equal (swidget->name, "key-manager"))
-		gnome_help_display (PACKAGE, "toc", NULL);
+		gnome_help_display (PACKAGE, NULL, NULL);
 	else
 		gnome_help_display (PACKAGE, swidget->name, NULL);
 }
