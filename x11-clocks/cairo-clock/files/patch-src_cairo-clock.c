--- src/cairo-clock.c.orig	2008-02-27 11:02:57 UTC
+++ src/cairo-clock.c
@@ -1486,7 +1486,7 @@ main (int    argc,
 					      "mainWindow");
 	g_pErrorDialog = glade_xml_get_widget (pGladeXml,
 					      "errorDialog");
-
+#if 0
 	if (!gdk_screen_is_composited (gtk_widget_get_screen (g_pMainWindow)))
 	{
 		gtk_window_set_icon_from_file (GTK_WINDOW (g_pErrorDialog),
@@ -1495,7 +1495,7 @@ main (int    argc,
 		gtk_dialog_run (GTK_DIALOG (g_pErrorDialog));
 		exit (2);
 	}
-
+#endif
 	g_pPopUpMenu = glade_xml_get_widget (pGladeXml,
 					     "popUpMenu");
 	pSettingsMenuItem = glade_xml_get_widget (pGladeXml,
