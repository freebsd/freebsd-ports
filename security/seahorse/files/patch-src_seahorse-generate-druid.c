--- src/seahorse-generate-druid.c.orig	Wed Dec 22 15:22:02 2004
+++ src/seahorse-generate-druid.c	Wed Dec 22 15:22:22 2004
@@ -173,8 +173,9 @@
 gboolean
 on_druidpagestandard4_next (GnomeDruidPage *gnomedruidpage, GtkWidget *widget, SeahorseWidget *swidget)
 {
+	GtkWidget *druidpage;
 	g_print("go to finish\n");
-	GtkWidget *druidpage = glade_xml_get_widget (swidget->xml, "druidpagefinish1");
+	druidpage = glade_xml_get_widget (swidget->xml, "druidpagefinish1");
 		
 	gnome_druid_page_prepare (GNOME_DRUID_PAGE(druidpage));
 	gtk_widget_show (druidpage);
