
$FreeBSD$

--- src/plugins/GUI/gui_preferences.c.orig
+++ src/plugins/GUI/gui_preferences.c
@@ -1315,6 +1315,8 @@
 	{
 		GSList *combo_theme_slist;
 		GSList *combo_icons_slist;
+		GSList *combo_skins_slist;
+
 		if (plugins_updated)
 		{
 			GIOChannel *ch = g_io_channel_new_file(g_build_filename(config->configdir, "modules.load", NULL), "w",
@@ -1433,7 +1435,7 @@
 		entry = g_object_get_data(G_OBJECT(adv_vbox), "combo_skins");
 		g_return_if_fail(entry != NULL);
 
-		GSList *combo_skins_slist = g_object_get_data(G_OBJECT(entry), "combo_skins_slist");
+		combo_skins_slist = g_object_get_data(G_OBJECT(entry), "combo_skins_slist");
 
 		if (gtk_combo_box_get_active(GTK_COMBO_BOX(entry))) {
 		    ggadu_config_var_set(gui_handler, "skin", (gpointer) g_strdup(g_slist_nth_data(combo_skins_slist, gtk_combo_box_get_active(GTK_COMBO_BOX(entry)))));
