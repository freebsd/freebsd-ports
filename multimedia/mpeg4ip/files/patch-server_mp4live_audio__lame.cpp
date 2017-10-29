--- server/mp4live/audio_lame.cpp.orig	2006-08-07 18:27:27 UTC
+++ server/mp4live/audio_lame.cpp
@@ -38,7 +38,7 @@ static int get_mpeg_type_for_samplerate 
 {
   for (uint x = 0; x < 3; x++) {
     for (uint y = 0; y < 4; y++) {
-      if (samplerate_table[x][y] == sr) {
+      if (lame_get_samplerate(x,y) == sr) {
 	return x;
       }
     }
@@ -61,7 +61,7 @@ static uint32_t *lame_bitrate_for_sample
   lame_global_flags *lameParams;
 
   for (iy = 0; iy < 16; iy++) {
-    if (bitrate_table[ix][iy] > 0) {
+    if (lame_get_bitrate(ix,iy) > 0) {
       lameParams = lame_init();
       lame_set_num_channels(lameParams, chans);
       lame_set_in_samplerate(lameParams, samplerate);
@@ -70,11 +70,11 @@ static uint32_t *lame_bitrate_for_sample
       lame_set_quality(lameParams,2);
       lame_set_bWriteVbrTag(lameParams,0);
       lame_set_brate(lameParams,
-		     bitrate_table[ix][iy]);
+		     lame_get_bitrate(ix,iy));
 
       if (lame_init_params(lameParams) != -1) {
 	if (lame_get_in_samplerate(lameParams) == lame_get_out_samplerate(lameParams)) {
-	  ret[*ret_size] = bitrate_table[ix][iy] * 1000;
+	  ret[*ret_size] = lame_get_bitrate(ix,iy) * 1000;
 	  *ret_size = *ret_size + 1;
 	}
       }
