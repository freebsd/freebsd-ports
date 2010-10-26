--- mozilla/media/libsydneyaudio/src/sydney_audio_oss.c.orig	2010-10-12 21:45:53.000000000 +0400
+++ mozilla/media/libsydneyaudio/src/sydney_audio_oss.c	2010-10-25 23:33:08.919096567 +0400
@@ -258,6 +258,7 @@
 int
 sa_stream_destroy(sa_stream_t *s) {
   int result = SA_SUCCESS;
+  pthread_t thread_id;
 
   if (s == NULL) {
     return SA_SUCCESS;
@@ -265,8 +266,10 @@
 
   pthread_mutex_lock(&s->mutex);
 
+  thread_id = s->thread_id;
+
   /*
-   * This causes the thread sending data to ALSA to stop
+   * This causes the thread sending data to OSS to stop
    */
   s->thread_id = 0;
 
@@ -281,6 +284,8 @@
 
   pthread_mutex_unlock(&s->mutex);
 
+  pthread_join(thread_id, NULL);
+
   /*
    * Release resources.
    */


