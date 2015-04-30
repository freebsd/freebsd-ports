--- libmpdemux/demux_ogg.c.orig	2013-07-09 18:33:16.000000000 +0200
+++ libmpdemux/demux_ogg.c	2015-03-25 01:47:19.439377000 +0100
@@ -50,21 +50,21 @@
 #endif
 
 #ifdef CONFIG_OGGTHEORA
-#include <theora/theora.h>
-int _ilog (unsigned int); /* defined in many places in theora/lib/ */
+#include <theora/theoradec.h>
 #endif
 
 #define BLOCK_SIZE 4096
 
 /* Theora decoder context : we won't be able to interpret granule positions
- * without using theora_granule_time with the theora_state of the stream.
+ * without using th_granule_time with the th_dec_ctx of the stream.
  * This is duplicated in `vd_theora.c'; put this in a common header?
  */
 #ifdef CONFIG_OGGTHEORA
 typedef struct theora_struct_st {
-    theora_state   st;
-    theora_comment cc;
-    theora_info    inf;
+    th_setup_info *tsi;
+    th_dec_ctx    *tctx;
+    th_comment     tc;
+    th_info        ti;		
 } theora_struct_t;
 #endif
 
@@ -117,7 +117,7 @@
     float   samplerate; /// granulpos 2 time
     int64_t lastpos;
     int32_t lastsize;
-    int     keyframe_frequency_force;
+    int     keyframe_granule_shift;
 
     // Logical stream state
     ogg_stream_state stream;
@@ -300,11 +300,10 @@
            have theora_state st, until all header packets were passed to the
            decoder. */
         if (!pack->bytes || !(*data&0x80)) {
-            int keyframe_granule_shift = _ilog(os->keyframe_frequency_force - 1);
-            int64_t iframemask = (1 << keyframe_granule_shift) - 1;
+            int64_t iframemask = (1 << os->keyframe_granule_shift) - 1;
 
             if (pack->granulepos >= 0) {
-                os->lastpos  = pack->granulepos >> keyframe_granule_shift;
+                os->lastpos  = pack->granulepos >> os->keyframe_granule_shift;
                 os->lastpos += pack->granulepos & iframemask;
                 *keyframe = (pack->granulepos & iframemask) == 0;
             } else {
@@ -888,14 +887,15 @@
 #ifdef CONFIG_OGGTHEORA
         } else if (pack.bytes >= 7 && !strncmp (&pack.packet[1], "theora", 6)) {
             int errorCode = 0;
-            theora_info inf;
-            theora_comment cc;
+            th_info ti;
+            th_comment tc;
+	    th_setup_info *tsi = NULL;	
 
-            theora_info_init (&inf);
-            theora_comment_init (&cc);
+            th_info_init (&ti);
+            th_comment_init (&tc);
 
-            errorCode = theora_decode_header (&inf, &cc, &pack);
-            if (errorCode) {
+            errorCode = th_decode_headerin (&ti, &tc, &tsi, &pack);
+            if (errorCode < 0) {
                 mp_msg(MSGT_DEMUX, MSGL_ERR,
                        "Theora header parsing failed: %i \n", errorCode);
             } else {
@@ -904,30 +904,32 @@
                 sh_v->bih = calloc(1, sizeof(*sh_v->bih));
                 sh_v->bih->biSize        = sizeof(*sh_v->bih);
                 sh_v->bih->biCompression = sh_v->format = FOURCC_THEORA;
-                sh_v->fps = ((double)inf.fps_numerator) / (double)inf.fps_denominator;
-                sh_v->frametime = ((double)inf.fps_denominator) / (double)inf.fps_numerator;
-                sh_v->disp_w = sh_v->bih->biWidth  = inf.frame_width;
-                sh_v->disp_h = sh_v->bih->biHeight = inf.frame_height;
+                sh_v->fps = ((double)ti.fps_numerator) / (double)ti.fps_denominator;
+                sh_v->frametime = ((double)ti.fps_denominator) / (double)ti.fps_numerator;
+                sh_v->i_bps = ti.target_bitrate / 8;
+                sh_v->disp_w = sh_v->bih->biWidth  = ti.frame_width;
+                sh_v->disp_h = sh_v->bih->biHeight = ti.frame_height;
                 sh_v->bih->biBitCount  = 24;
                 sh_v->bih->biPlanes    = 3;
                 sh_v->bih->biSizeImage = ((sh_v->bih->biBitCount / 8) * sh_v->bih->biWidth * sh_v->bih->biHeight);
                 ogg_d->subs[ogg_d->num_sub].samplerate               = sh_v->fps;
                 ogg_d->subs[ogg_d->num_sub].theora                   = 1;
-                ogg_d->subs[ogg_d->num_sub].keyframe_frequency_force = inf.keyframe_frequency_force;
+                ogg_d->subs[ogg_d->num_sub].keyframe_granule_shift = ti.keyframe_granule_shift;
                 ogg_d->subs[ogg_d->num_sub].id                       = n_video;
                 n_video++;
                 mp_msg(MSGT_DEMUX, MSGL_INFO,
                        "[Ogg] stream %d: video (Theora v%d.%d.%d), -vid %d\n",
                        ogg_d->num_sub,
-                       (int)inf.version_major,
-                       (int)inf.version_minor,
-                       (int)inf.version_subminor,
+                       (int)ti.version_major,
+                       (int)ti.version_minor,
+                       (int)ti.version_subminor,
                        n_video - 1);
                 if (mp_msg_test(MSGT_HEADER, MSGL_V))
                     print_video_header(sh_v->bih, MSGL_V);
             }
-            theora_comment_clear(&cc);
-            theora_info_clear(&inf);
+            th_comment_clear(&tc);
+            th_info_clear(&ti);
+            th_setup_free(tsi);
 #endif /* CONFIG_OGGTHEORA */
         } else if (pack.bytes >= 4 && !strncmp (&pack.packet[0], "fLaC", 4)) {
             sh_a = new_sh_audio_aid(demuxer, ogg_d->num_sub, n_audio);
