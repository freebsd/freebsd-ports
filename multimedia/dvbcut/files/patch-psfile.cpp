--- src/psfile.cpp~	Fri Apr 13 19:36:27 2007
+++ src/psfile.cpp	Tue May  1 21:45:19 2007
@@ -100,7 +100,7 @@
       streamnumber[sid]=audiostream(audiostreams);
       stream *S=&s[audiostream(audiostreams++)];
       S->id=sid;
-      S->dec=&ac3_decoder;
+      S->dec=&liba52_decoder;
       S->type=streamtype::ac3audio;
       if (audiostreams>=MAXAUDIOSTREAMS)
         break;
