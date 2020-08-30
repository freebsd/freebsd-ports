--- libnemo-private/nemo-global-preferences.c.orig	2020-08-30 07:04:30 UTC
+++ libnemo-private/nemo-global-preferences.c
@@ -36,6 +36,19 @@
 
 static gboolean ignore_view_metadata = FALSE;
 
+GSettings *nemo_preferences;
+GSettings *nemo_icon_view_preferences;
+GSettings *nemo_list_view_preferences;
+GSettings *nemo_compact_view_preferences;
+GSettings *nemo_desktop_preferences;
+GSettings *nemo_tree_sidebar_preferences;
+GSettings *nemo_window_state;
+GSettings *gnome_lockdown_preferences;
+GSettings *gnome_background_preferences;
+GSettings *gnome_media_handling_preferences;
+GSettings *gnome_terminal_preferences;
+GSettings *cinnamon_privacy_preferences;
+
 /*
  * Public functions
  */
