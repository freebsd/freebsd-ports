--- audtool/audtool.c.orig	Fri Dec  1 15:24:24 2006
+++ audtool/audtool.c	Fri Dec  1 15:40:57 2006
@@ -377,6 +377,8 @@
 
 void playlist_delete(gint session, gint argc, gchar **argv)
 {
+	gint playpos;
+
 	if (argc < 3)
 	{
 		g_print("%s: invalid parameters for playlist-delete.\n", argv[0]);
@@ -384,7 +386,7 @@
 		return;
 	}
 
-	gint playpos = atoi(argv[2]);
+	playpos = atoi(argv[2]);
 
 	if (playpos < 1 || playpos > xmms_remote_get_playlist_length(session))
 	{
@@ -406,6 +408,9 @@
 
 void playlist_song(gint session, gint argc, gchar **argv)
 {
+	gint playpos;
+	gchar *song;
+
 	if (argc < 3)
 	{
 		g_print("%s: invalid parameters for playlist-song-title.\n", argv[0]);
@@ -413,7 +418,7 @@
 		return;
 	}
 
-	gint playpos = atoi(argv[2]);
+	playpos = atoi(argv[2]);
 
 	if (playpos < 1 || playpos > xmms_remote_get_playlist_length(session))
 	{
@@ -421,7 +426,7 @@
 		return;
 	}
 
-	gchar *song = xmms_remote_get_playlist_title(session, playpos - 1);
+	song = xmms_remote_get_playlist_title(session, playpos - 1);
 
 	g_print("%s\n", song);
 }
@@ -429,6 +434,8 @@
 
 void playlist_song_length(gint session, gint argc, gchar **argv)
 {
+	gint playpos, frames, length;
+
 	if (argc < 3)
 	{
 		g_print("%s: invalid parameters for playlist-song-length.\n", argv[0]);
@@ -436,7 +443,7 @@
 		return;
 	}
 
-	gint playpos = atoi(argv[2]);
+	playpos = atoi(argv[2]);
 
 	if (playpos < 1 || playpos > xmms_remote_get_playlist_length(session))
 	{
@@ -444,14 +451,16 @@
 		return;
 	}
 
-	gint frames = xmms_remote_get_playlist_time(session, playpos - 1);
-	gint length = frames / 1000;
+	frames = xmms_remote_get_playlist_time(session, playpos - 1);
+	length = frames / 1000;
 
 	g_print("%d:%.2d\n", length / 60, length % 60);
 }
 
 void playlist_song_length_seconds(gint session, gint argc, gchar **argv)
 {
+	gint playpos, frames, length;
+
 	if (argc < 3)
 	{
 		g_print("%s: invalid parameters for playlist-song-length-seconds.\n", argv[0]);
@@ -459,7 +468,7 @@
 		return;
 	}
 
-	gint playpos = atoi(argv[2]);
+	playpos = atoi(argv[2]);
 
 	if (playpos < 1 || playpos > xmms_remote_get_playlist_length(session))
 	{
@@ -467,14 +476,16 @@
 		return;
 	}
 
-	gint frames = xmms_remote_get_playlist_time(session, playpos - 1);
-	gint length = frames / 1000;
+	frames = xmms_remote_get_playlist_time(session, playpos - 1);
+	length = frames / 1000;
 
 	g_print("%d\n", length);
 }
 
 void playlist_song_length_frames(gint session, gint argc, gchar **argv)
 {
+	gint playpos, frames;
+
 	if (argc < 3)
 	{
 		g_print("%s: invalid parameters for playlist-song-length-frames.\n", argv[0]);
@@ -482,7 +493,7 @@
 		return;
 	}
 
-	gint playpos = atoi(argv[2]);
+	playpos = atoi(argv[2]);
 
 	if (playpos < 1 || playpos > xmms_remote_get_playlist_length(session))
 	{
@@ -490,7 +501,7 @@
 		return;
 	}
 
-	gint frames = xmms_remote_get_playlist_time(session, playpos - 1);
+	frames = xmms_remote_get_playlist_time(session, playpos - 1);
 
 	g_print("%d\n", frames);
 }
