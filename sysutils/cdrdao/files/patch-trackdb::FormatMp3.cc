--- trackdb/FormatMp3.cc.orig	2010-06-06 16:45:00.000000000 +0200
+++ trackdb/FormatMp3.cc	2010-06-06 16:45:36.000000000 +0200
@@ -111,6 +111,7 @@ FormatSupport::Status FormatMp3::madInit
 
   // Initialize libao for WAV output;
   ao_sample_format out_format;
+  memset(&out_format, 0, sizeof(out_format));
   out_format.bits = 16;
   out_format.rate = 44100;
   out_format.channels = 2;
