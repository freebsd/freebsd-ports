i+--- guvcview/video_capture.c.orig	2024-11-02 13:15:33 UTC
+++ guvcview/video_capture.c
@@ -34,6 +34,7 @@
 /* support for internationalization - i18n */
 #include <libintl.h>
 #include <locale.h>
+#include <pthread_np.h>
 
 #include "config.h"
 #include "core_io.h"
@@ -82,6 +83,7 @@ static __THREAD_TYPE encoder_thread;
 static v4l2_dev_t *my_vd = NULL;
 
 static __THREAD_TYPE encoder_thread;
+static __THREAD_TYPE encoder_audio_thread;
 
 static int my_encoder_status = 0;
 
@@ -622,8 +624,8 @@ static void *audio_processing_loop(void *data) {
   encoder_context_t *encoder_ctx = (encoder_context_t *)data;
 
   if (debug_level > 1)
-    printf("GUVCVIEW: audio thread (tid: %u)\n",
-           (unsigned int)syscall(SYS_gettid));
+    printf("GUVCVIEW: audio thread (tid: %d)\n",
+           pthread_getthreadid_np());
 
   audio_context_t *audio_ctx = get_audio_context();
   if (!audio_ctx) {
@@ -717,8 +719,8 @@ static void *encoder_loop(void *data) {
   my_encoder_status = 1;
 
   if (debug_level > 1)
-    printf("GUVCVIEW: encoder thread (tid: %u)\n",
-           (unsigned int)syscall(SYS_gettid));
+    printf("GUVCVIEW: encoder thread (tid: %d)\n",
+           pthread_getthreadid_np());
 
   /*get the audio context*/
   audio_context_t *audio_ctx = get_audio_context();
@@ -830,8 +832,7 @@ static void *encoder_loop(void *data) {
       fprintf(stderr, "GUVCVIEW: encoder audio thread creation failed (%i)\n",
               ret);
     else if (debug_level > 2)
-      printf("GUVCVIEW: created audio encoder thread with tid: %u\n",
-             (unsigned int)encoder_audio_thread);
+      printf("GUVCVIEW: created audio encoder thread\n");
   }
 
   while (video_capture_get_save_video()) {
@@ -914,8 +915,8 @@ void *capture_loop(void *data) {
   quit = 0;
 
   if (debug_level > 1)
-    printf("GUVCVIEW: capture thread (tid: %u)\n",
-           (unsigned int)syscall(SYS_gettid));
+    printf("GUVCVIEW: capture thread (tid: %d)\n",
+           pthread_getthreadid_np()); 
 
   int ret = 0;
 
@@ -1210,8 +1211,7 @@ int start_encoder_thread() {
   if (ret)
     fprintf(stderr, "GUVCVIEW: encoder thread creation failed (%i)\n", ret);
   else if (debug_level > 2)
-    printf("GUVCVIEW: created encoder thread with tid: %u\n",
-           (unsigned int)encoder_thread);
+    printf("GUVCVIEW: created encoder thread\n");
 
   return ret;
 }
