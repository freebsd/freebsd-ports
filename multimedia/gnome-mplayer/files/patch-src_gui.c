--- src/gui.c.orig	2014-04-24 03:38:08 UTC
+++ src/gui.c
@@ -50,6 +50,237 @@
 #include "database.h"
 #endif
 
+GtkWidget *window;
+ 
+GtkMenuItem *menuitem_edit_random;
+GtkMenuItem *menuitem_edit_loop;
+GtkMenuItem *menuitem_edit_play_single;
+GtkWidget *repeat;
+GtkWidget *shuffle;
+GtkMenuItem *menuitem_edit_select_audio_lang;
+GtkMenuItem *menuitem_edit_select_sub_lang;
+GtkWidget *tracks;
+GtkWidget *subtitles;
+
+GtkMenuItem *menuitem_view_info;
+GtkMenuItem *menuitem_view_playlist;
+
+GtkMenuItem *menuitem_prev;
+GtkMenuItem *menuitem_next;
+
+GtkWidget *pane;
+GtkWidget *hbox;
+
+GtkWidget *media;
+GtkWidget *cover_art;
+GtkWidget *audio_meter;
+
+GtkWidget *details_table;
+
+GtkWidget *play_event_box;
+
+GtkWidget *prev_event_box;
+GtkWidget *next_event_box;
+GtkWidget *menu_event_box;
+GtkWidget *fs_event_box;
+
+GmtkMediaTracker *tracker;
+GtkWidget *vol_slider;
+
+GtkWidget *conf_volume_label;
+
+#ifdef GTK2_12_ENABLED
+#else
+GtkTooltips *tooltip;
+#endif
+
+// Playlist container
+GtkWidget *plvbox;
+GSList *lang_group;
+GSList *audio_group;
+
+GtkAccelGroup *accel_group;
+
+gint buckets[METER_BARS];
+gint max_buckets[METER_BARS];
+gchar **accel_keys;
+gchar **accel_keys_description;
+
+gint cache_size;
+gint plugin_audio_cache_size;
+gint plugin_video_cache_size;
+gboolean forcecache;
+gint osdlevel;
+gint pplevel;
+gint streaming;
+gboolean showcontrols;
+gboolean showsubtitles;
+gint fullscreen;
+gint init_fullscreen;
+gboolean videopresent;
+gboolean playlist;
+gint embed_window;
+gint window_x;
+gint window_y;
+gint control_id;
+gboolean softvol;
+gboolean remember_softvol;
+gdouble volume_softvol;
+gint volume_gain;
+gint pref_volume;
+gint verbose;
+gint autostart;
+//gint actual_x, actual_y;
+//gint play_x, play_y;
+gint last_window_width, last_window_height;
+//gchar vm[10];
+gchar *vo;
+gchar *option_vo;
+gboolean use_hardware_codecs;
+gboolean use_crystalhd_codecs;
+AudioDevice audio_device;
+gchar *audio_device_name;
+gint audio_channels;
+gboolean use_hw_audio;
+gboolean disable_deinterlace;
+gboolean disable_framedrop;
+gboolean disable_context_menu;
+gboolean disable_fullscreen;
+gboolean disable_pause_on_click;
+gboolean enable_global_menu;
+gboolean enable_nautilus_plugin;
+gint loop;
+gint start_second;
+gint play_length;
+gint random_order;
+gboolean dontplaynext;
+gboolean autopause;
+gchar *path;
+gint js_state;
+gchar *rpconsole;
+gchar *rpcontrols;
+gboolean control_instance;
+gchar *playlistname;
+gboolean ok_to_play;
+gchar *subtitle;
+gchar *alang;
+gchar *slang;
+gchar *metadata_codepage;
+gboolean use_mplayer2;
+gboolean vertical_layout;
+gboolean playlist_visible;
+gboolean details_visible;
+gboolean restore_controls;
+gboolean update_control_flag;
+//gint restore_pane;
+//gboolean updating_recent;
+gboolean disable_ass;
+gboolean disable_embeddedfonts;
+gboolean disable_animation;
+gint auto_hide_timeout;
+gboolean always_hide_after_timeout;
+gboolean mouse_over_controls;
+gchar *subtitlefont;
+gdouble subtitle_scale;
+gchar *subtitle_codepage;
+gchar *subtitle_color;
+gboolean subtitle_outline;
+gboolean subtitle_shadow;
+gint subtitle_margin;
+gint subtitle_fuzziness;
+gboolean quit_on_complete;
+gchar *mplayer_bin;
+gchar *mplayer_dvd_device;
+gchar *option_dvd_device;
+gchar *extraopts;
+gboolean resize_on_new_media;
+gboolean single_instance;
+gboolean replace_and_play;
+gboolean bring_to_front;
+gboolean show_notification;
+gboolean show_status_icon;
+gchar *gpod_mount_point;
+gboolean disable_cover_art_fetch;
+//gboolean updating_recent;
+gboolean large_buttons;
+GtkIconSize button_size;
+gboolean skip_fixed_allocation_on_show;
+gboolean skip_fixed_allocation_on_hide;
+gboolean mouse_wheel_changes_volume;
+ResumeMode resume_mode;
+
+gboolean remember_loc;
+gboolean use_remember_loc;
+gboolean save_loc;
+gint loc_window_x;
+gint loc_window_y;
+gint loc_window_height;
+gint loc_window_width;
+gint loc_panel_position;
+gboolean keep_on_top;
+
+gboolean cancel_folder_load;
+
+GThreadPool *retrieve_metadata_pool;
+GMutex *retrieve_mutex;
+GMutex *set_mutex;
+
+gboolean use_mediakeys;
+gboolean use_defaultpl;
+
+gboolean qt_disabled;
+gboolean real_disabled;
+gboolean wmp_disabled;
+gboolean dvx_disabled;
+gboolean midi_disabled;
+gboolean embedding_disabled;
+gboolean disable_embedded_scaling;
+
+GArray *data;
+GArray *max_data;
+gboolean reading_af_export;
+
+//gboolean sub_source_file;
+
+// layout variables
+gint non_fs_width;
+gint non_fs_height;
+
+// playlist stuff
+GtkListStore *playliststore;
+GtkTreeIter iter;
+GtkTreeIter *next_iter;
+GtkTreeSelection *selection;
+GtkWidget *list;
+
+// preference store
+GmPrefStore *gm_store;
+GmPrefStore *gmp_store;
+
+// cover
+gchar *cover_art_uri;
+
+gchar *default_playlist;
+gboolean safe_to_save_default_playlist;
+
+#ifdef GTK2_12_ENABLED
+GtkRecentManager *recent_manager;
+#endif
+
+#ifdef LIBGDA_ENABLED
+GdaConnection *db_connection;
+#endif
+
+gboolean screensaver_disabled;
+
+gint window_width, window_height;
+
+GtkWidget *plclose;
+IdleData *idledata;
+GMutex *fs_controls_lock;
+PLAYSTATE guistate;
+PLAYSTATE lastguistate;
+
 static GdkWindow *window_container;
 static GtkWidget *fs_window;
 static GtkWidget *fs_controls;
