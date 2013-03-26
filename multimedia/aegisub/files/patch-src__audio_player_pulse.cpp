--- src/audio_player_pulse.cpp.orig
+++ src/audio_player_pulse.cpp
@@ -144,7 +144,7 @@
 	pa_stream_set_write_callback(stream, (pa_stream_request_cb_t)pa_stream_write, this);
 
 	// Connect stream
-	paerror = pa_stream_connect_playback(stream, NULL, NULL, PA_STREAM_INTERPOLATE_TIMING|PA_STREAM_NOT_MONOTONOUS|PA_STREAM_AUTO_TIMING_UPDATE, NULL, NULL);
+	paerror = pa_stream_connect_playback(stream, NULL, NULL, (pa_stream_flags_t) (PA_STREAM_INTERPOLATE_TIMING|PA_STREAM_NOT_MONOTONOUS|PA_STREAM_AUTO_TIMING_UPDATE), NULL, NULL);
 	if (paerror) {
 		printf("PulseAudio reported error: %s (%d)\n", pa_strerror(paerror), paerror);
 		wxString s(pa_strerror(paerror), wxConvUTF8);
@@ -217,7 +217,7 @@
 
 	play_start_time = 0;
 	pa_threaded_mainloop_lock(mainloop);
-	paerror = pa_stream_get_time(stream, &play_start_time);
+	paerror = pa_stream_get_time(stream, (pa_usec_t*) &play_start_time);
 	pa_threaded_mainloop_unlock(mainloop);
 	if (paerror) {
 		printf("PulseAudio player: Error getting stream time: %s (%d)\n", pa_strerror(paerror), paerror);
