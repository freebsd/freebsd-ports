--- src/xine-engine/audio_out.c.orig	Thu Dec 25 09:24:36 2003
+++ src/xine-engine/audio_out.c	Wed Jan  7 21:19:54 2004
@@ -429,7 +429,7 @@
   num_frames = pts_len * this->frames_per_kpts / 1024;
 
   xprintf (this->xine, XINE_VERBOSITY_DEBUG,
-           "inserting %d 0-frames to fill a gap of %" PRId64 " pts\n", num_frames, pts_len);
+           "inserting %d 0-frames to fill a gap of %lld pts\n", num_frames, pts_len);
 
   if ((this->output.mode == AO_CAP_MODE_A52) || (this->output.mode == AO_CAP_MODE_AC5)) {
     write_pause_burst(this,num_frames);
@@ -792,7 +792,7 @@
     this->resample_sync_factor = (avg_gap < 0) ? 0.995 : 1.005;
 
     llprintf (LOG_RESAMPLE_SYNC,
-              "sample rate adjusted to reduce gap: gap=%" PRId64 "\n", avg_gap);
+              "sample rate adjusted to reduce gap: gap=%lld\n", avg_gap);
     return 0;
 
   } else if (info->reduce_gap && abs(avg_gap) < 50) {
@@ -826,7 +826,7 @@
        * this during calculation */
       num_frames = (this->do_resample) ? (buf->num_frames * this->frame_rate_factor)
         : buf->num_frames;
-      printf("audio_out: gap=%5" PRId64 ";  gap_diff=%5" PRId64 ";  frame_diff=%3.0f;  drift_factor=%f\n",
+      printf("audio_out: gap=%5lld;  gap_diff=%5lld;  frame_diff=%3.0f;  drift_factor=%f\n",
              avg_gap, gap_diff, num_frames * info->window * info->last_factor,
              this->resample_sync_factor);
 #endif
@@ -981,7 +981,7 @@
      */
 
     hw_vpts = cur_time;
-    lprintf ("current delay is %" PRId64 ", current time is %" PRId64 "\n", delay, cur_time);
+    lprintf ("current delay is %lld, current time is %lld\n", delay, cur_time);
 
     /* External A52 decoder delay correction */
     if ((this->output.mode==AO_CAP_MODE_A52) || (this->output.mode==AO_CAP_MODE_AC5)) 
@@ -994,7 +994,7 @@
      * calculate gap:
      */
     gap = in_buf->vpts - hw_vpts;
-    lprintf ("hw_vpts : %" PRId64 " buffer_vpts : %" PRId64 " gap : %" PRId64 "\n",
+    lprintf ("hw_vpts : %lld buffer_vpts : %lld gap : %lld\n",
              hw_vpts, in_buf->vpts, gap);
 
     if (this->resample_sync_method) {
@@ -1018,7 +1018,7 @@
       lprintf ("loop: drop package, next fifo\n");
       fifo_append (this->free_fifo, in_buf);
 
-      lprintf ("audio package (vpts = %" PRId64 ", gap = %" PRId64 ") dropped\n",
+      lprintf ("audio package (vpts = %lld, gap = %lld) dropped\n",
                in_buf->vpts, gap);
       in_buf = NULL;
 
@@ -1252,7 +1252,7 @@
   this->frames_per_kpts   = (this->output.rate * 1024) / 90000;
   this->audio_step        = ((int64_t)90000 * (int64_t)32768) / (int64_t)this->input.rate;
   
-  lprintf ("audio_step %" PRId64 " pts per 32768 frames\n", this->audio_step);
+  lprintf ("audio_step %lld pts per 32768 frames\n", this->audio_step);
   return this->output.rate;
 }
 
@@ -1355,7 +1355,7 @@
 
   buf->extra_info->vpts = buf->vpts;
          
-  lprintf ("ao_put_buffer, pts=%" PRId64 ", vpts=%" PRId64 ", flushmode=%d\n",
+  lprintf ("ao_put_buffer, pts=%lld, vpts=%lld, flushmode=%d\n",
            pts, buf->vpts, this->discard_buffers);
 
   if (!this->discard_buffers) 
