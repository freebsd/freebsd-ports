--- src/xine-engine/audio_out.c.orig	Wed Mar 17 05:21:58 2004
+++ src/xine-engine/audio_out.c	Wed Apr  7 23:09:00 2004
@@ -63,6 +63,9 @@
 /* required for FNDELAY decl */
 #define _BSD_SOURCE 1
 
+#define INT16_MAX 0x7fff
+#define INT16_MIN (-0x7fff-1)
+
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
@@ -452,7 +455,7 @@
   num_frames = pts_len * this->frames_per_kpts / 1024;
 
   xprintf (this->xine, XINE_VERBOSITY_DEBUG,
-           "inserting %d 0-frames to fill a gap of %" PRId64 " pts\n", num_frames, pts_len);
+           "inserting %d 0-frames to fill a gap of %lld pts\n", num_frames, pts_len);
 
   if ((this->output.mode == AO_CAP_MODE_A52) || (this->output.mode == AO_CAP_MODE_AC5)) {
     write_pause_burst(this,num_frames);
@@ -831,7 +834,7 @@
     this->resample_sync_factor = (avg_gap < 0) ? 0.995 : 1.005;
 
     llprintf (LOG_RESAMPLE_SYNC,
-              "sample rate adjusted to reduce gap: gap=%" PRId64 "\n", avg_gap);
+              "sample rate adjusted to reduce gap: gap=%lld\n", avg_gap);
     return 0;
 
   } else if (info->reduce_gap && abs(avg_gap) < 50) {
@@ -865,7 +868,7 @@
        * this during calculation */
       num_frames = (this->do_resample) ? (buf->num_frames * this->frame_rate_factor)
         : buf->num_frames;
-      printf("audio_out: gap=%5" PRId64 ";  gap_diff=%5" PRId64 ";  frame_diff=%3.0f;  drift_factor=%f\n",
+      printf("audio_out: gap=%5lld;  gap_diff=%5lld;  frame_diff=%3.0f;  drift_factor=%f\n",
              avg_gap, gap_diff, num_frames * info->window * info->last_factor,
              this->resample_sync_factor);
 #endif
@@ -1020,7 +1023,7 @@
      */
 
     hw_vpts = cur_time;
-    lprintf ("current delay is %" PRId64 ", current time is %" PRId64 "\n", delay, cur_time);
+    lprintf ("current delay is %lld, current time is %lld\n", delay, cur_time);
 
     /* External A52 decoder delay correction */
     if ((this->output.mode==AO_CAP_MODE_A52) || (this->output.mode==AO_CAP_MODE_AC5)) 
@@ -1033,7 +1036,7 @@
      * calculate gap:
      */
     gap = in_buf->vpts - hw_vpts;
-    lprintf ("hw_vpts : %" PRId64 " buffer_vpts : %" PRId64 " gap : %" PRId64 "\n",
+    lprintf ("hw_vpts : %lld buffer_vpts : %lld gap : %lld\n",
              hw_vpts, in_buf->vpts, gap);
 
     if (this->resample_sync_method) {
@@ -1057,7 +1060,7 @@
       lprintf ("loop: drop package, next fifo\n");
       fifo_append (this->free_fifo, in_buf);
 
-      lprintf ("audio package (vpts = %" PRId64 ", gap = %" PRId64 ") dropped\n",
+      lprintf ("audio package (vpts = %lld, gap = %lld) dropped\n",
                in_buf->vpts, gap);
       in_buf = NULL;
 
@@ -1286,7 +1289,7 @@
   this->frames_per_kpts   = (this->output.rate * 1024) / 90000;
   this->audio_step        = ((int64_t)90000 * (int64_t)32768) / (int64_t)this->input.rate;
   
-  lprintf ("audio_step %" PRId64 " pts per 32768 frames\n", this->audio_step);
+  lprintf ("audio_step %lld pts per 32768 frames\n", this->audio_step);
   return this->output.rate;
 }
 
@@ -1395,7 +1398,7 @@
 
   buf->extra_info->vpts = buf->vpts;
          
-  lprintf ("ao_put_buffer, pts=%" PRId64 ", vpts=%" PRId64 ", flushmode=%d\n",
+  lprintf ("ao_put_buffer, pts=%lld, vpts=%lld, flushmode=%d\n",
            pts, buf->vpts, this->discard_buffers);
 
   if (!this->discard_buffers) 
