Apply the enclosed patch.

Patch attached with submission follows:

--- xmms/main.c.orig	2006-07-16 09:40:04.000000000 -0400
+++ xmms/main.c	2008-11-16 19:35:56.000000000 -0500
@@ -93,6 +93,10 @@
 gboolean pposition_broken = FALSE;
 static pthread_mutex_t title_mutex = PTHREAD_MUTEX_INITIALIZER;
 
+gboolean g_stop_fadeout_pressed = FALSE;
+GTimeVal g_stop_fadeout_pressed_date;
+int g_stop_fadeout_volumel, g_stop_fadeout_volumer;
+
 extern gchar *plugin_dir_list[];
 
 enum
@@ -288,7 +292,7 @@
 	{N_("/Playback/Stop"), "V", mainwin_general_menu_callback, MAINWIN_GENERAL_STOP, "<Item>"},
 	{N_("/Playback/Next"), "B", mainwin_general_menu_callback, MAINWIN_GENERAL_NEXT, "<Item>"},
 	{N_("/Playback/-"), NULL, NULL, 0, "<Separator>"},
-/*      {N_("/Playback/Stop with Fadeout"),"<Shift>V",mainwin_general_menu_callback,MAINWIN_GENERAL_STOPFADE,"<Item>"}, */
+        {N_("/Playback/Stop with Fadeout"),"<Shift>V",mainwin_general_menu_callback,MAINWIN_GENERAL_STOPFADE,"<Item>"},
 	{N_("/Playback/Back 5 Seconds"), NULL, mainwin_general_menu_callback, MAINWIN_GENERAL_BACK5SEC, "<Item>"},
 	{N_("/Playback/Fwd 5 Seconds"), NULL, mainwin_general_menu_callback, MAINWIN_GENERAL_FWD5SEC, "<Item>"},
 	{N_("/Playback/Start of List"), "<control>Z", mainwin_general_menu_callback, MAINWIN_GENERAL_START, "<Item>"},
@@ -2538,6 +2542,14 @@
 	input_stop();
 }
 
+void mainwin_stopfade_pushed(void)
+{
+
+  input_get_volume( &g_stop_fadeout_volumel, &g_stop_fadeout_volumer );
+  g_stop_fadeout_pressed = TRUE;
+  g_get_current_time( &g_stop_fadeout_pressed_date ); 
+}
+
 void mainwin_shuffle_pushed(gboolean toggled)
 {
 	GtkWidget *widget;
@@ -3035,6 +3047,7 @@
 		playlist_next();
 		break;
 	case MAINWIN_GENERAL_STOPFADE:
+		mainwin_stopfade_pushed();
 		break;
 	case MAINWIN_GENERAL_BACK5SEC:
 		if (get_input_playing() && playlist_get_current_length() != -1)
@@ -4176,6 +4189,34 @@
 #endif
 }
 
+gint stop_fadeout_idle(gpointer   data)
+{
+  GTimeVal time, delta;
+  static const gfloat s_fade_time = 3.0f;
+
+  g_get_current_time( &time );
+
+  delta.tv_sec = time.tv_sec - g_stop_fadeout_pressed_date.tv_sec;
+  delta.tv_usec = time.tv_usec - g_stop_fadeout_pressed_date.tv_usec;
+
+  if( g_stop_fadeout_pressed )
+  {
+    if( (int)s_fade_time != delta.tv_sec )
+    {
+      const gfloat fading = 1.0f - ( 1.0f * delta.tv_sec + 1.0e-6f * delta.tv_usec ) / s_fade_time;
+      //printf( "%f\n", fading );
+      input_set_volume( g_stop_fadeout_volumel * fading, g_stop_fadeout_volumer * fading );
+    } else
+    {
+      g_stop_fadeout_pressed = FALSE;
+      mainwin_clear_song_info();
+      input_stop();
+      input_set_volume( g_stop_fadeout_volumel , g_stop_fadeout_volumer );
+    }
+  }
+  return TRUE;
+}
+
 int main(int argc, char **argv)
 {
 	char *filename;
@@ -4312,8 +4353,9 @@
 	
 	mainwin_timeout_tag = gtk_timeout_add(10, idle_func, NULL); 
 	playlist_start_get_info_thread();
-
+	g_idle_add( stop_fadeout_idle, NULL );
 	enable_x11r5_session_management(argc, argv);
+	
 	gtk_main();
 	GDK_THREADS_LEAVE();
 


