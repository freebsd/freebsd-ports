--- libcaja-private/caja-global-preferences.c.orig	2020-08-28 11:29:20 UTC
+++ libcaja-private/caja-global-preferences.c
@@ -34,6 +34,19 @@
 #include <eel/eel-string.h>
 #include <glib/gi18n.h>
 
+GSettings *caja_preferences;
+GSettings *caja_media_preferences;
+GSettings *caja_window_state;
+GSettings *caja_icon_view_preferences;
+GSettings *caja_desktop_preferences;
+GSettings *caja_tree_sidebar_preferences;
+GSettings *caja_compact_view_preferences;
+GSettings *caja_list_view_preferences;
+GSettings *caja_extension_preferences;
+
+GSettings *mate_background_preferences;
+GSettings *mate_lockdown_preferences;
+
 /*
  * Public functions
  */
