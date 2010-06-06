--- src/playaudio.cpp.orig	2010-06-06 16:19:25.000000000 +0200
+++ src/playaudio.cpp	2010-06-06 16:19:47.000000000 +0200
@@ -55,6 +55,7 @@ public:
 
       ao_sample_format format;
 
+      memset(&format, 0, sizeof(format));
       format.bits = 16;
       format.channels = channels;
       format.rate = samplerate;
