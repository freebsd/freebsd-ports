--- ./avidemux/ADM_encoder/adm_encx264.cpp.orig	2008-06-30 20:30:09.000000000 +0200
+++ ./avidemux/ADM_encoder/adm_encx264.cpp	2008-07-10 17:27:51.000000000 +0200
@@ -271,6 +271,7 @@
 {
   uint32_t    bitrate;
 
+  _delayed = 0;
   ADM_assert (_state == enc_Pass1);
   printf ("\n[x264] Starting pass 2 (%d x %d)\n", _w, _h);
 
