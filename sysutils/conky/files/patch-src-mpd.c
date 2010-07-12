--- src/mpd.c.orig
+++ src/mpd.c
@@ -113,23 +113,24 @@ void free_mpd(void)
 
 static void *update_mpd_thread(void *) __attribute__((noreturn));
 
-void update_mpd(void)
+int update_mpd(void)
 {
 	int interval;
 	static timed_thread *thread = NULL;
 
 	if (thread)
-		return;
+		return 0;
 
 	interval = info.music_player_interval * 1000000;
 	thread = timed_thread_create(&update_mpd_thread, &thread, interval);
 	if (!thread) {
 		NORM_ERR("Failed to create MPD timed thread");
-		return;
+		return 0;
 	}
 	timed_thread_register(thread, &thread);
 	if (timed_thread_run(thread))
 		NORM_ERR("Failed to run MPD timed thread");
+	return 0;
 }
 
 /* stringMAXdup dups at most text_buffer_size bytes */
