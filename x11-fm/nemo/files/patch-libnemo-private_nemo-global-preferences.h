--- libnemo-private/nemo-global-preferences.h.orig	2020-08-30 07:04:30 UTC
+++ libnemo-private/nemo-global-preferences.h
@@ -239,18 +239,18 @@ char *nemo_global_preferences_get_default_folder_viewe
 gboolean nemo_global_preferences_get_ignore_view_metadata (void);
 gint nemo_global_preferences_get_tooltip_flags (void);
 
-GSettings *nemo_preferences;
-GSettings *nemo_icon_view_preferences;
-GSettings *nemo_list_view_preferences;
-GSettings *nemo_compact_view_preferences;
-GSettings *nemo_desktop_preferences;
-GSettings *nemo_tree_sidebar_preferences;
-GSettings *nemo_window_state;
-GSettings *gnome_lockdown_preferences;
-GSettings *gnome_background_preferences;
-GSettings *gnome_media_handling_preferences;
-GSettings *gnome_terminal_preferences;
-GSettings *cinnamon_privacy_preferences;
+extern GSettings *nemo_preferences;
+extern GSettings *nemo_icon_view_preferences;
+extern GSettings *nemo_list_view_preferences;
+extern GSettings *nemo_compact_view_preferences;
+extern GSettings *nemo_desktop_preferences;
+extern GSettings *nemo_tree_sidebar_preferences;
+extern GSettings *nemo_window_state;
+extern GSettings *gnome_lockdown_preferences;
+extern GSettings *gnome_background_preferences;
+extern GSettings *gnome_media_handling_preferences;
+extern GSettings *gnome_terminal_preferences;
+extern GSettings *cinnamon_privacy_preferences;
 
 G_END_DECLS
 
