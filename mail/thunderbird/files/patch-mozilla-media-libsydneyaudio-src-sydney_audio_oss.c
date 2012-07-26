--- mozilla/media/libsydneyaudio/src/sydney_audio_oss.c~
+++ mozilla/media/libsydneyaudio/src/sydney_audio_oss.c
@@ -446,6 +446,10 @@ static void audio_callback(void* data)
           printf("!");  /* not enough audio data */
 #endif
           bytes = bytes-bytes_to_copy;
+          struct timespec ts = {0, 1000000};
+          pthread_mutex_unlock(&s->mutex);
+          nanosleep(&ts, NULL);
+          pthread_mutex_lock(&s->mutex);
           break;
         }
         free(s->bl_head);
