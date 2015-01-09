Right click context menu with wrong icon (bug #10652)

--- thunar/thunar-location-buttons.c.orig	2013-12-18 23:41:57 UTC
+++ thunar/thunar-location-buttons.c
@@ -175,7 +175,7 @@ static const GtkActionEntry action_entri
   { "location-buttons-open", GTK_STOCK_OPEN, N_("_Open"), "", NULL, G_CALLBACK (thunar_location_buttons_action_open), },
   { "location-buttons-open-in-new-tab", NULL, N_("Open in New Tab"), "", NULL, G_CALLBACK (thunar_location_buttons_action_open_in_new_tab), },
   { "location-buttons-open-in-new-window", NULL, N_("Open in New Window"), "", NULL, G_CALLBACK (thunar_location_buttons_action_open_in_new_window), },
-  { "location-buttons-create-folder", NULL, N_("Create _Folder..."), "", NULL, G_CALLBACK (thunar_location_buttons_action_create_folder), },
+  { "location-buttons-create-folder", "folder-new", N_("Create _Folder..."), "", NULL, G_CALLBACK (thunar_location_buttons_action_create_folder), },
   { "location-buttons-empty-trash", NULL, N_("_Empty Trash"), "", N_("Delete all files and folders in the Trash"), G_CALLBACK (thunar_location_buttons_action_empty_trash), },
   { "location-buttons-paste-into-folder", GTK_STOCK_PASTE, N_("Paste Into Folder"), "", NULL, G_CALLBACK (thunar_location_buttons_action_paste_into_folder), },
   { "location-buttons-properties", GTK_STOCK_PROPERTIES, N_("_Properties..."), "", NULL, G_CALLBACK (thunar_location_buttons_action_properties), },
