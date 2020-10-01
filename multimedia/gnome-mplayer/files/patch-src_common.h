--- src/common.h.orig	2014-04-24 03:38:08 UTC
+++ src/common.h
@@ -150,8 +150,8 @@ typedef enum {
     QUIT
 } PLAYSTATE;
 
-PLAYSTATE guistate;
-PLAYSTATE lastguistate;
+extern PLAYSTATE guistate;
+extern PLAYSTATE lastguistate;
 
 typedef struct _IdleData {
     gchar info[1024];
@@ -190,7 +190,7 @@ typedef struct _IdleData {
 #endif
 } IdleData;
 
-IdleData *idledata;
+extern IdleData *idledata;
 
 enum {
     ITEM_COLUMN,
@@ -283,10 +283,10 @@ typedef struct _ButtonDef {
 } ButtonDef;
 
 #define METER_BARS 		40
-gint buckets[METER_BARS];
-gint max_buckets[METER_BARS];
-gchar **accel_keys;
-gchar **accel_keys_description;
+extern gint buckets[METER_BARS];
+extern gint max_buckets[METER_BARS];
+extern gchar **accel_keys;
+extern gchar **accel_keys_description;
 
 //Define MIME for DnD
 #define DRAG_NAME_0		"text/plain"
@@ -296,158 +296,158 @@ gchar **accel_keys_description;
 #define DRAG_NAME_2		"STRING"
 #define DRAG_INFO_2		2
 
-gint cache_size;
-gint plugin_audio_cache_size;
-gint plugin_video_cache_size;
-gboolean forcecache;
-gint osdlevel;
-gint pplevel;
-gint streaming;
-gboolean showcontrols;
-gboolean showsubtitles;
-gint fullscreen;
-gint init_fullscreen;
-gboolean videopresent;
-gboolean playlist;
-gint embed_window;
-gint window_x;
-gint window_y;
-gint control_id;
-gboolean softvol;
-gboolean remember_softvol;
-gdouble volume_softvol;
-gint volume_gain;
-gint pref_volume;
-gint verbose;
-gint autostart;
+extern gint cache_size;
+extern gint plugin_audio_cache_size;
+extern gint plugin_video_cache_size;
+extern gboolean forcecache;
+extern gint osdlevel;
+extern gint pplevel;
+extern gint streaming;
+extern gboolean showcontrols;
+extern gboolean showsubtitles;
+extern gint fullscreen;
+extern gint init_fullscreen;
+extern gboolean videopresent;
+extern gboolean playlist;
+extern gint embed_window;
+extern gint window_x;
+extern gint window_y;
+extern gint control_id;
+extern gboolean softvol;
+extern gboolean remember_softvol;
+extern gdouble volume_softvol;
+extern gint volume_gain;
+extern gint pref_volume;
+extern gint verbose;
+extern gint autostart;
 //gint actual_x, actual_y;
 //gint play_x, play_y;
-gint last_window_width, last_window_height;
+extern gint last_window_width, last_window_height;
 //gchar vm[10];
-gchar *vo;
-gchar *option_vo;
-gboolean use_hardware_codecs;
-gboolean use_crystalhd_codecs;
-AudioDevice audio_device;
-gchar *audio_device_name;
-gint audio_channels;
-gboolean use_hw_audio;
-gboolean disable_deinterlace;
-gboolean disable_framedrop;
-gboolean disable_context_menu;
-gboolean disable_fullscreen;
-gboolean disable_pause_on_click;
-gboolean enable_global_menu;
-gboolean enable_nautilus_plugin;
-gint loop;
-gint start_second;
-gint play_length;
-gint random_order;
-gboolean dontplaynext;
-gboolean autopause;
-gchar *path;
-gint js_state;
-gchar *rpconsole;
-gchar *rpcontrols;
-gboolean control_instance;
-gchar *playlistname;
-gboolean ok_to_play;
-gchar *subtitle;
-gchar *alang;
-gchar *slang;
-gchar *metadata_codepage;
-gboolean use_mplayer2;
-gboolean vertical_layout;
-gboolean playlist_visible;
-gboolean details_visible;
-gboolean restore_controls;
-gboolean update_control_flag;
+extern gchar *vo;
+extern gchar *option_vo;
+extern gboolean use_hardware_codecs;
+extern gboolean use_crystalhd_codecs;
+extern AudioDevice audio_device;
+extern gchar *audio_device_name;
+extern gint audio_channels;
+extern gboolean use_hw_audio;
+extern gboolean disable_deinterlace;
+extern gboolean disable_framedrop;
+extern gboolean disable_context_menu;
+extern gboolean disable_fullscreen;
+extern gboolean disable_pause_on_click;
+extern gboolean enable_global_menu;
+extern gboolean enable_nautilus_plugin;
+extern gint loop;
+extern gint start_second;
+extern gint play_length;
+extern gint random_order;
+extern gboolean dontplaynext;
+extern gboolean autopause;
+extern gchar *path;
+extern gint js_state;
+extern gchar *rpconsole;
+extern gchar *rpcontrols;
+extern gboolean control_instance;
+extern gchar *playlistname;
+extern gboolean ok_to_play;
+extern gchar *subtitle;
+extern gchar *alang;
+extern gchar *slang;
+extern gchar *metadata_codepage;
+extern gboolean use_mplayer2;
+extern gboolean vertical_layout;
+extern gboolean playlist_visible;
+extern gboolean details_visible;
+extern gboolean restore_controls;
+extern gboolean update_control_flag;
 //gint restore_pane;
-gboolean disable_ass;
-gboolean disable_embeddedfonts;
-gboolean disable_animation;
-gint auto_hide_timeout;
-gboolean always_hide_after_timeout;
-gboolean mouse_over_controls;
-gchar *subtitlefont;
-gdouble subtitle_scale;
-gchar *subtitle_codepage;
-gchar *subtitle_color;
-gboolean subtitle_outline;
-gboolean subtitle_shadow;
-gint subtitle_margin;
-gint subtitle_fuzziness;
-gboolean quit_on_complete;
-gchar *mplayer_bin;
-gchar *mplayer_dvd_device;
-gchar *option_dvd_device;
-gchar *extraopts;
-gboolean resize_on_new_media;
-gboolean single_instance;
-gboolean replace_and_play;
-gboolean bring_to_front;
-gboolean show_notification;
-gboolean show_status_icon;
-gchar *gpod_mount_point;
-gboolean disable_cover_art_fetch;
+extern gboolean disable_ass;
+extern gboolean disable_embeddedfonts;
+extern gboolean disable_animation;
+extern gint auto_hide_timeout;
+extern gboolean always_hide_after_timeout;
+extern gboolean mouse_over_controls;
+extern gchar *subtitlefont;
+extern gdouble subtitle_scale;
+extern gchar *subtitle_codepage;
+extern gchar *subtitle_color;
+extern gboolean subtitle_outline;
+extern gboolean subtitle_shadow;
+extern gint subtitle_margin;
+extern gint subtitle_fuzziness;
+extern gboolean quit_on_complete;
+extern gchar *mplayer_bin;
+extern gchar *mplayer_dvd_device;
+extern gchar *option_dvd_device;
+extern gchar *extraopts;
+extern gboolean resize_on_new_media;
+extern gboolean single_instance;
+extern gboolean replace_and_play;
+extern gboolean bring_to_front;
+extern gboolean show_notification;
+extern gboolean show_status_icon;
+extern gchar *gpod_mount_point;
+extern gboolean disable_cover_art_fetch;
 //gboolean updating_recent;
-gboolean large_buttons;
-GtkIconSize button_size;
-gboolean skip_fixed_allocation_on_show;
-gboolean skip_fixed_allocation_on_hide;
-gboolean mouse_wheel_changes_volume;
-ResumeMode resume_mode;
+extern gboolean large_buttons;
+extern GtkIconSize button_size;
+extern gboolean skip_fixed_allocation_on_show;
+extern gboolean skip_fixed_allocation_on_hide;
+extern gboolean mouse_wheel_changes_volume;
+extern ResumeMode resume_mode;
 
-gboolean remember_loc;
-gboolean use_remember_loc;
-gboolean save_loc;
-gint loc_window_x;
-gint loc_window_y;
-gint loc_window_height;
-gint loc_window_width;
-gint loc_panel_position;
-gboolean keep_on_top;
+extern gboolean remember_loc;
+extern gboolean use_remember_loc;
+extern gboolean save_loc;
+extern gint loc_window_x;
+extern gint loc_window_y;
+extern gint loc_window_height;
+extern gint loc_window_width;
+extern gint loc_panel_position;
+extern gboolean keep_on_top;
 
-gboolean cancel_folder_load;
+extern gboolean cancel_folder_load;
 
-GThreadPool *retrieve_metadata_pool;
-GMutex *retrieve_mutex;
-GMutex *set_mutex;
+extern GThreadPool *retrieve_metadata_pool;
+extern GMutex *retrieve_mutex;
+extern GMutex *set_mutex;
 
-gboolean use_mediakeys;
-gboolean use_defaultpl;
+extern gboolean use_mediakeys;
+extern gboolean use_defaultpl;
 
-gboolean qt_disabled;
-gboolean real_disabled;
-gboolean wmp_disabled;
-gboolean dvx_disabled;
-gboolean midi_disabled;
-gboolean embedding_disabled;
-gboolean disable_embedded_scaling;
+extern gboolean qt_disabled;
+extern gboolean real_disabled;
+extern gboolean wmp_disabled;
+extern gboolean dvx_disabled;
+extern gboolean midi_disabled;
+extern gboolean embedding_disabled;
+extern gboolean disable_embedded_scaling;
 
-GArray *data;
-GArray *max_data;
-gboolean reading_af_export;
+extern GArray *data;
+extern GArray *max_data;
+extern gboolean reading_af_export;
 
 //gboolean sub_source_file;
 
 // layout variables
-gint non_fs_width;
-gint non_fs_height;
+extern gint non_fs_width;
+extern gint non_fs_height;
 
 // playlist stuff
-GtkListStore *playliststore;
-GtkTreeIter iter;
-GtkTreeIter *next_iter;
-GtkTreeSelection *selection;
-GtkWidget *list;
+extern GtkListStore *playliststore;
+extern GtkTreeIter iter;
+extern GtkTreeIter *next_iter;
+extern GtkTreeSelection *selection;
+extern GtkWidget *list;
 
 // preference store
-GmPrefStore *gm_store;
-GmPrefStore *gmp_store;
+extern GmPrefStore *gm_store;
+extern GmPrefStore *gmp_store;
 
 // cover
-gchar *cover_art_uri;
+extern gchar *cover_art_uri;
 
 GtkWidget *create_window(gint windowid);
 void show_window(gint windowid);
@@ -523,18 +523,18 @@ void set_media_player_attributes(GtkWidget * widget);
 
 void retrieve_metadata(gpointer data, gpointer user_data);
 
-gchar *default_playlist;
-gboolean safe_to_save_default_playlist;
+extern gchar *default_playlist;
+extern gboolean safe_to_save_default_playlist;
 
 gboolean async_play_iter(void *data);
 
 #ifdef GTK2_12_ENABLED
-GtkRecentManager *recent_manager;
+extern GtkRecentManager *recent_manager;
 void recent_manager_changed_callback(GtkRecentManager * recent_manager, gpointer data);
 #endif
 
 #ifdef LIBGDA_ENABLED
-GdaConnection *db_connection;
+extern GdaConnection *db_connection;
 #endif
 
 #endif                          /* _COMMON_H */
