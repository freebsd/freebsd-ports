--- src/plugins/GUI/gui_preferences.c.orig	Fri Aug 12 10:21:26 2005
+++ src/plugins/GUI/gui_preferences.c	Fri Oct  7 12:38:50 2005
@@ -1329,6 +1329,9 @@
 	{
 		GSList *combo_theme_slist;
 		GSList *combo_icons_slist;
+		GSList *combo_skins_slist;
+		GSList *dict_slist;
+
 		if (plugins_updated)
 		{
 			GIOChannel *ch = g_io_channel_new_file(g_build_filename(config->configdir, "modules.load", NULL), "w",
@@ -1362,7 +1365,7 @@
 		ggadu_config_var_set(gui_handler, "use_spell", (gpointer) gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(entry)));
 
 		entry = g_object_get_data(G_OBJECT(chat_vbox), "combo_spell");
-		GSList *dict_slist = g_object_get_data(G_OBJECT(entry), "dictionary_slist");
+		dict_slist = g_object_get_data(G_OBJECT(entry), "dictionary_slist");
 
 		g_return_if_fail(entry != NULL);
 
@@ -1448,7 +1451,7 @@
 		entry = g_object_get_data(G_OBJECT(adv_vbox), "combo_skins");
 		g_return_if_fail(entry != NULL);
 
-		GSList *combo_skins_slist = g_object_get_data(G_OBJECT(entry), "combo_skins_slist");
+		combo_skins_slist = g_object_get_data(G_OBJECT(entry), "combo_skins_slist");
 
 		if (gtk_combo_box_get_active(GTK_COMBO_BOX(entry))) {
 		    ggadu_config_var_set(gui_handler, "skin", (gpointer) g_strdup(g_slist_nth_data(combo_skins_slist, gtk_combo_box_get_active(GTK_COMBO_BOX(entry)))));
