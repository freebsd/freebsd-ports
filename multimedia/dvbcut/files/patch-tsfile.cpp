--- src/tsfile.cpp~	Fri Apr 13 19:36:27 2007
+++ src/tsfile.cpp	Tue May  1 21:45:36 2007
@@ -78,7 +78,7 @@
     stream *S=&s[audiostream(audiostreams++)];
     S->id=it->second;
     if (it->first==0xbd) {
-      S->dec=&ac3_decoder;
+      S->dec=&liba52_decoder;
       S->enc=&ac3_encoder;
       S->type=streamtype::ac3audio;
       } else {
