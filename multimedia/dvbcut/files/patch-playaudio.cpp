--- src/playaudio.cpp~	Fri Apr 13 19:36:27 2007
+++ src/playaudio.cpp	Sat Jun  2 20:51:00 2007
@@ -38,7 +38,10 @@
   const uint8_t *d=(const uint8_t*)data;
 
   while (len>0) {
-    int16_t samples[MIN_BUFFER_SAMPLES >? avcc->frame_size];
+    int samples_dim = avcc->frame_size;
+    if (samples_dim < MIN_BUFFER_SAMPLES)
+	samples_dim = MIN_BUFFER_SAMPLES;
+    int16_t samples[samples_dim];
     int frame_size;
 
     int bytesDecoded=avcodec_decode_audio(avcc,samples,&frame_size,(uint8_t*)d,len);
