--- Tools/sound/AudioOutputSink.m.orig	2010-06-06 18:12:07.000000000 +0200
+++ Tools/sound/AudioOutputSink.m	2010-06-06 18:12:53.000000000 +0200
@@ -72,6 +72,7 @@
       return nil;
     }
   
+  memset(&_format, 0, sizeof(_format));
   _format.channels = (int)channelCount;
   _format.rate = (int)sampleRate;
   
