--- src/connect.c.orig	Sun May 18 15:51:07 2003
+++ src/connect.c	Sun May 18 15:51:52 2003
@@ -264,13 +264,15 @@
   gtk_box_pack_start (GTK_BOX (vbxMain), vbxBanner, TRUE, TRUE, 1);
   gtk_widget_show (vbxBanner);
 
-  g_sprintf (banner_lang, "banner-%s.png", g_strndup ((gchar*)gtk_get_default_language (), 2));
+  banner_lang = g_strdup_printf ("banner-%s.png", g_strndup ((gchar*)gtk_get_default_language (), 2));
 
   if (find_pixmap_file (banner_lang)) {
     imgBanner = create_pixmap (frmConnect, banner_lang);
   } else {
     imgBanner = create_pixmap (frmConnect, "banner.png");
   }
+
+  g_free(banner_lang);
   //imgBanner = create_pixmap (frmConnect, "banner.png");
   gtk_widget_set_name (imgBanner, "imgBanner");
   gtk_widget_show (imgBanner);
