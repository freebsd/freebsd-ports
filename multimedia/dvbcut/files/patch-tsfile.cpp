--- src/tsfile.cpp~	2007-04-13 19:36:27.000000000 +0200
+++ src/tsfile.cpp	2007-11-15 09:38:58.606927367 +0100
@@ -22,7 +22,9 @@
 #include <list>
 #include <utility>
 
+extern "C" {
 #include <ffmpeg/avcodec.h>
+}
 
 tsfile::tsfile(const std::string &filename, inbuffer &b, int initial_offset)
     : mpgfile(filename, b, initial_offset)
@@ -78,12 +80,12 @@
     stream *S=&s[audiostream(audiostreams++)];
     S->id=it->second;
     if (it->first==0xbd) {
-      S->dec=&ac3_decoder;
-      S->enc=&ac3_encoder;
+      S->dec=avcodec_find_decoder(CODEC_ID_AC3);
+      S->enc=avcodec_find_encoder(CODEC_ID_AC3);
       S->type=streamtype::ac3audio;
       } else {
-      S->dec=&mp2_decoder;
-      S->enc=&mp2_encoder;
+      S->dec=avcodec_find_decoder(CODEC_ID_MP2);
+      S->enc=avcodec_find_encoder(CODEC_ID_MP2);
       S->type=streamtype::mpegaudio;
       }
     if (audiostreams>=MAXAUDIOSTREAMS)
@@ -98,8 +100,8 @@
     S->allocavcc();
     S->avcc->codec_type=CODEC_TYPE_VIDEO;
     S->avcc->codec_id=CODEC_ID_MPEG2VIDEO;
-    S->dec=&mpeg2video_decoder;
-    S->enc=&mpeg2video_encoder;
+    S->dec=avcodec_find_decoder(CODEC_ID_MPEG2VIDEO);
+    S->enc=avcodec_find_encoder(CODEC_ID_MPEG2VIDEO);
     S->type=streamtype::mpeg2video;
     }
 
