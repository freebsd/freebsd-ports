--- src/popup_group.c.orig	Wed Sep 29 11:16:39 2004
+++ src/popup_group.c	Wed Oct 20 02:54:15 2004
@@ -40,14 +40,15 @@
 void kf_popup_groups_menu_attach (GladeXML *glade, KfJabberRosterItem *roster_item) {
 	GtkWidget *parent;
 	GtkWidget *menu;
+	GtkWidget *new_group, *separator;
+	GList *groups;
 
 	parent = glade_xml_get_widget (glade, "popup_group");
 	if ((menu = gtk_menu_item_get_submenu (GTK_MENU_ITEM (parent)))) {
 		gtk_widget_destroy (menu);
 	}
 //	} else {
-		GtkWidget *new_group, *separator;
-		GList *groups = kf_gui_get_groups ();
+		groups = kf_gui_get_groups ();
 
 		menu = gtk_menu_new ();
 
