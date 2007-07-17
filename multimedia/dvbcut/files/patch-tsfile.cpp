--- src/tsfile.cpp~	Fri Apr 13 19:36:27 2007
+++ src/tsfile.cpp	2007-07-17 01:12:25 +0200
@@ -22,7 +22,9 @@
 #include <list>
 #include <utility>
 
+extern "C" {
 #include <ffmpeg/avcodec.h>
+}
 
 tsfile::tsfile(const std::string &filename, inbuffer &b, int initial_offset)
     : mpgfile(filename, b, initial_offset)
@@ -78,7 +80,7 @@
     stream *S=&s[audiostream(audiostreams++)];
     S->id=it->second;
     if (it->first==0xbd) {
-      S->dec=&ac3_decoder;
+      S->dec=&liba52_decoder;
       S->enc=&ac3_encoder;
       S->type=streamtype::ac3audio;
       } else {
