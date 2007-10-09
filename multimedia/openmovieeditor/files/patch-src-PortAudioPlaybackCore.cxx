--- src/PortAudioPlaybackCore.cxx.orig	Fri Oct  5 01:19:48 2007
+++ src/PortAudioPlaybackCore.cxx	Fri Oct  5 01:20:55 2007
@@ -187,7 +187,7 @@
 	m_lastFrame++;
 	pthread_mutex_lock( &condition_mutex );
 	int64_t diff = m_lastFrame - m_currentFrame;
-	if ( abs( diff ) > VIDEO_DRIFT_LIMIT ) {
+	if ( ::llabs( diff ) > VIDEO_DRIFT_LIMIT ) {
 		if ( diff > 0 ) {
 			while( ( m_lastFrame - m_currentFrame ) > VIDEO_DRIFT_LIMIT && Pa_StreamActive( g_stream ) ) {
 				pthread_cond_wait( &condition_cond, &condition_mutex );
