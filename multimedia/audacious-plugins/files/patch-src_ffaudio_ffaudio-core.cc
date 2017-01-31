--- src/ffaudio/ffaudio-core.cc.orig	2016-12-06 14:15:33 UTC
+++ src/ffaudio/ffaudio-core.cc
@@ -99,7 +99,8 @@ struct ScopedContext
 
 struct ScopedPacket : public AVPacket
 {
-    ScopedPacket () { av_init_packet (this); }
+    ScopedPacket () : AVPacket ()
+        { av_init_packet (this); }
 
 #if CHECK_LIBAVCODEC_VERSION (55, 25, 100, 55, 16, 0)
     ~ScopedPacket () { av_packet_unref (this); }
@@ -553,8 +554,10 @@ bool FFaudio::play (const char * filenam
         /* On EOF, send an empty packet to "flush" the decoder */
         /* Otherwise, make a mutable (shallow) copy of the real packet */
         AVPacket tmp;
-        if (eof)
+        if (eof) {
+            tmp = AVPacket ();
             av_init_packet (& tmp);
+        }
         else
             tmp = pkt;
 
