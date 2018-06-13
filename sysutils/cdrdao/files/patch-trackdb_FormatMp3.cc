--- trackdb/FormatMp3.cc.orig	2018-05-15 13:30:52 UTC
+++ trackdb/FormatMp3.cc
@@ -111,6 +111,7 @@ FormatSupport::Status FormatMp3::madInit
 
   // Initialize libao for WAV output;
   ao_sample_format out_format;
+  memset(&out_format, 0, sizeof(out_format));
   out_format.bits = 16;
   out_format.rate = 44100;
   out_format.channels = 2;
