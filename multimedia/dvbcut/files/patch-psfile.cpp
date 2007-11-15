--- src/psfile.cpp~	2007-04-13 19:36:27.000000000 +0200
+++ src/psfile.cpp	2007-11-15 09:40:42.110171154 +0100
@@ -19,7 +19,9 @@
 #include "psfile.h"
 #include "streamhandle.h"
 #include "stream.h"
+extern "C" {
 #include <ffmpeg/avcodec.h>
+}
 
 psfile::psfile(const std::string &filename, inbuffer &b, int initial_offset)
     : mpgfile(filename, b, initial_offset)
@@ -90,7 +92,7 @@
       streamnumber[sid]=audiostream(audiostreams);
       stream *S=&s[audiostream(audiostreams++)];
       S->id=sid;
-      S->dec=&mp2_decoder;
+      S->dec=avcodec_find_decoder(CODEC_ID_MP2);
       S->type=streamtype::mpegaudio;
       if (audiostreams>=MAXAUDIOSTREAMS)
         break;
@@ -100,7 +102,7 @@
       streamnumber[sid]=audiostream(audiostreams);
       stream *S=&s[audiostream(audiostreams++)];
       S->id=sid;
-      S->dec=&ac3_decoder;
+      S->dec=avcodec_find_decoder(CODEC_ID_AC3);
       S->type=streamtype::ac3audio;
       if (audiostreams>=MAXAUDIOSTREAMS)
         break;
@@ -114,8 +116,8 @@
     S->allocavcc();
     S->avcc->codec_type=CODEC_TYPE_VIDEO;
     S->avcc->codec_id=CODEC_ID_MPEG2VIDEO;
-    S->dec=&mpeg2video_decoder;
-    S->enc=&mpeg2video_encoder;
+    S->dec=avcodec_find_decoder(CODEC_ID_MPEG2VIDEO);
+    S->enc=avcodec_find_encoder(CODEC_ID_MPEG2VIDEO);
     S->type=streamtype::mpeg2video;
     }
 
