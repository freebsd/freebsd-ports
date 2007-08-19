--- src/tsfile.cpp~	2007-04-13 19:36:27.000000000 +0200
+++ src/tsfile.cpp	2007-08-19 11:51:32.753587432 +0200
@@ -22,7 +22,9 @@
 #include <list>
 #include <utility>
 
+extern "C" {
-#include <ffmpeg/avcodec.h>
+#include <ffmpeg/allcodecs.h>
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
