--- src/plugins/GUI/gui_preferences.c.orig	Tue Jan  4 16:54:23 2005
+++ src/plugins/GUI/gui_preferences.c	Fri Jan 28 00:32:36 2005
@@ -618,6 +618,8 @@
 #endif
 	GtkWidget *label0_align, *label1_align, *label2_align;
 	GtkWidget *label3_align;
+	GtkWidget *exp;
+	GtkWidget *frm;
 
 	chat_vbox = gtk_vbox_new(FALSE, 5);
 
@@ -694,8 +696,8 @@
 	gtk_table_set_row_spacings(GTK_TABLE(tabbox), 7);
 	gtk_table_set_col_spacings(GTK_TABLE(tabbox), 0);
 	
-	GtkWidget *exp = gtk_expander_new(_("More advanced options"));
-	GtkWidget *frm = gtk_frame_new(_("Default size of window"));
+	exp = gtk_expander_new(_("More advanced options"));
+	frm = gtk_frame_new(_("Default size of window"));
 	gtk_frame_set_shadow_type(GTK_FRAME(frm),GTK_SHADOW_ETCHED_OUT);
 	gtk_container_add(GTK_CONTAINER(frm), tabbox);
 	gtk_container_add(GTK_CONTAINER(exp), frm);
@@ -746,6 +748,7 @@
 
 static GtkWidget *create_advanced_tab()
 {
+	GtkWidget *entry;
 	GtkWidget *hide_on_start;
 	GtkWidget *close_on_esc;
 	GtkWidget *blink_interval = NULL;
@@ -922,7 +925,7 @@
 	label = gtk_label_new(_("Web Browser:"));
 	gtk_container_add(GTK_CONTAINER(label4_align), label);
 
-	GtkWidget *entry = gtk_entry_new();
+	entry = gtk_entry_new();
 	gtk_table_attach_defaults(GTK_TABLE(tabbox2), label4_align, 0, 1, 0, 1);
 	gtk_table_attach_defaults(GTK_TABLE(tabbox2), entry, 1, 2, 0, 1);
 	g_object_set_data(G_OBJECT(adv_vbox), "browser_exec", entry);
@@ -1221,6 +1224,8 @@
 	response = gtk_dialog_run(GTK_DIALOG(preferences));
 	if (response == GTK_RESPONSE_ACCEPT)
 	{
+		GSList *combo_theme_slist;
+		GSList *combo_icons_slist;
 		if (plugins_updated)
 		{
 			GIOChannel *ch = g_io_channel_new_file(g_build_filename(config->configdir, "modules.load", NULL), "w",
@@ -1325,7 +1330,7 @@
 		entry = g_object_get_data(G_OBJECT(adv_vbox), "combo_theme");
 		g_return_if_fail(entry != NULL);
 
-		GSList *combo_theme_slist = g_object_get_data(G_OBJECT(entry), "combo_theme_slist");
+		combo_theme_slist = g_object_get_data(G_OBJECT(entry), "combo_theme_slist");
 		ggadu_config_var_set(gui_handler, "theme", (gpointer) g_strdup(g_slist_nth_data(combo_theme_slist, gtk_combo_box_get_active(GTK_COMBO_BOX(entry)))));
 
 		g_slist_foreach(combo_theme_slist, (GFunc) g_free, NULL);
@@ -1333,7 +1338,7 @@
 
 		entry = g_object_get_data(G_OBJECT(adv_vbox), "combo_icons");
 		g_return_if_fail(entry != NULL);
-		GSList *combo_icons_slist = g_object_get_data(G_OBJECT(entry), "combo_icons_slist");
+		combo_icons_slist = g_object_get_data(G_OBJECT(entry), "combo_icons_slist");
 		ggadu_config_var_set(gui_handler, "icons", (gpointer) g_strdup(g_slist_nth_data(combo_icons_slist, gtk_combo_box_get_active(GTK_COMBO_BOX(entry)))));
 		g_slist_free(combo_icons_slist);
 
