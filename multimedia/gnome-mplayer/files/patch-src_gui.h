--- src/gui.h.orig	2014-04-24 03:38:08 UTC
+++ src/gui.h
@@ -44,56 +44,56 @@
 
 #include "playlist.h"
 
-GtkWidget *window;
+extern GtkWidget *window;
 
-GtkMenuItem *menuitem_edit_random;
-GtkMenuItem *menuitem_edit_loop;
-GtkMenuItem *menuitem_edit_play_single;
-GtkWidget *repeat;
-GtkWidget *shuffle;
-GtkMenuItem *menuitem_edit_select_audio_lang;
-GtkMenuItem *menuitem_edit_select_sub_lang;
-GtkWidget *tracks;
-GtkWidget *subtitles;
+extern GtkMenuItem *menuitem_edit_random;
+extern GtkMenuItem *menuitem_edit_loop;
+extern GtkMenuItem *menuitem_edit_play_single;
+extern GtkWidget *repeat;
+extern GtkWidget *shuffle;
+extern GtkMenuItem *menuitem_edit_select_audio_lang;
+extern GtkMenuItem *menuitem_edit_select_sub_lang;
+extern GtkWidget *tracks;
+extern GtkWidget *subtitles;
 
-GtkMenuItem *menuitem_view_info;
-GtkMenuItem *menuitem_view_playlist;
+extern GtkMenuItem *menuitem_view_info;
+extern GtkMenuItem *menuitem_view_playlist;
 
-GtkMenuItem *menuitem_prev;
-GtkMenuItem *menuitem_next;
+extern GtkMenuItem *menuitem_prev;
+extern GtkMenuItem *menuitem_next;
 
-GtkWidget *pane;
-GtkWidget *hbox;
+extern GtkWidget *pane;
+extern GtkWidget *hbox;
 
-GtkWidget *media;
-GtkWidget *cover_art;
-GtkWidget *audio_meter;
+extern GtkWidget *media;
+extern GtkWidget *cover_art;
+extern GtkWidget *audio_meter;
 
-GtkWidget *details_table;
+extern GtkWidget *details_table;
 
-GtkWidget *play_event_box;
+extern GtkWidget *play_event_box;
 
-GtkWidget *prev_event_box;
-GtkWidget *next_event_box;
-GtkWidget *menu_event_box;
-GtkWidget *fs_event_box;
+extern GtkWidget *prev_event_box;
+extern GtkWidget *next_event_box;
+extern GtkWidget *menu_event_box;
+extern GtkWidget *fs_event_box;
 
-GmtkMediaTracker *tracker;
-GtkWidget *vol_slider;
+extern GmtkMediaTracker *tracker;
+extern GtkWidget *vol_slider;
 
-GtkWidget *conf_volume_label;
+extern GtkWidget *conf_volume_label;
 
 #ifdef GTK2_12_ENABLED
 #else
-GtkTooltips *tooltip;
+extern GtkTooltips *tooltip;
 #endif
 
 // Playlist container
-GtkWidget *plvbox;
-GSList *lang_group;
-GSList *audio_group;
+extern GtkWidget *plvbox;
+extern GSList *lang_group;
+extern GSList *audio_group;
 
-GtkAccelGroup *accel_group;
+extern GtkAccelGroup *accel_group;
 
 gboolean popup_handler(GtkWidget * widget, GdkEvent * event, void *data);
 gboolean delete_callback(GtkWidget * widget, GdkEvent * event, void *data);
@@ -138,7 +138,7 @@ void assign_default_keys();
 void reset_keys_callback(GtkButton * button, gpointer data);
 gint get_index_from_key_and_modifier(guint key, GdkModifierType modifier);
 
-GMutex *fs_controls_lock;
+extern GMutex *fs_controls_lock;
 void show_fs_controls();
 void hide_fs_controls();
 gboolean set_destroy(gpointer data);
