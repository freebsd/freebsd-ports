--- src/playaudio.cpp~	Fri Apr 13 19:36:27 2007
+++ src/playaudio.cpp	2007-07-17 01:11:15 +0200
@@ -19,7 +19,9 @@
 #ifdef HAVE_LIB_AO
 #include <stdio.h>
 #include <ao/ao.h>
+extern "C" {
 #include <ffmpeg/avcodec.h>
+}
 #include "playaudio.h"
 
 #define MIN_BUFFER_SAMPLES (1536*6)
@@ -38,7 +40,10 @@
   const uint8_t *d=(const uint8_t*)data;
 
   while (len>0) {
-    int16_t samples[MIN_BUFFER_SAMPLES >? avcc->frame_size];
+    int samples_dim = avcc->frame_size;
+    if (samples_dim < MIN_BUFFER_SAMPLES)
+	samples_dim = MIN_BUFFER_SAMPLES;
+    int16_t samples[samples_dim];
     int frame_size;
 
     int bytesDecoded=avcodec_decode_audio(avcc,samples,&frame_size,(uint8_t*)d,len);
