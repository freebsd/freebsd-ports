--- src/xine-engine/video_out.c.orig	Tue Apr  6 23:51:13 2004
+++ src/xine-engine/video_out.c	Tue Apr  6 23:51:43 2004
@@ -367,7 +367,7 @@
     cur_vpts = this->clock->get_current_time(this->clock);
     this->last_delivery_pts = cur_vpts;
 
-    lprintf ("got image oat master vpts %" PRId64 ". vpts for picture is %" PRId64 " (pts was %" PRId64 ")\n",
+    lprintf ("got image oat master vpts %lld. vpts for picture is %lld (pts was %lld)\n",
 	     cur_vpts, pic_vpts, img->pts);
 
     this->num_frames_delivered++;
@@ -408,7 +408,7 @@
   }
 
 
-  lprintf ("delivery diff : %" PRId64 ", current vpts is %" PRId64 ", %d frames to skip\n",
+  lprintf ("delivery diff : %lld, current vpts is %lld, %d frames to skip\n",
 	   diff, cur_vpts, frames_to_skip);
 
   if (!img->bad_frame) {
@@ -652,7 +652,7 @@
   
       if( !this->discard_frames ) {
         xine_log(this->xine, XINE_LOG_MSG,
-	         _("video_out: throwing away image with pts %" PRId64 " because it's too old (diff : %" PRId64 ").\n"), pts, diff);
+	         _("video_out: throwing away image with pts %lld because it's too old (diff : %lld).\n"), pts, diff);
 
         this->num_frames_discarded++;
       }
@@ -728,7 +728,7 @@
 
     if (this->img_backup && (this->redraw_needed==1)) {
 
-      lprintf("generating still frame (cur_vpts = %" PRId64 ") \n", cur_vpts);
+      lprintf("generating still frame (cur_vpts = %lld) \n", cur_vpts);
 
       /* keep playing still frames */
       pthread_mutex_lock( &this->free_img_buf_queue->mutex );
@@ -761,7 +761,7 @@
      * time to display frame "img" ?
      */
 
-    lprintf ("diff %" PRId64 "\n", diff);
+    lprintf ("diff %lld\n", diff);
 
     if (diff < 0) {
       pthread_mutex_unlock(&this->display_img_buf_queue->mutex);
@@ -807,7 +807,7 @@
 				       vo_frame_t *img, int64_t vpts) {
   xine_stream_t *stream;
 
-  lprintf ("displaying image with vpts = %" PRId64 "\n", img->vpts);
+  lprintf ("displaying image with vpts = %lld\n", img->vpts);
 
   /* no, this is not were proc_*() is usually called.
    * it's just to catch special cases like late or duplicated frames.
@@ -962,7 +962,7 @@
 
     vpts = this->clock->get_current_time (this->clock);
 
-    lprintf ("loop iteration at %" PRId64 "\n", vpts);
+    lprintf ("loop iteration at %lld\n", vpts);
 
     expire_frames (this, vpts);
     img = get_next_frame (this, vpts);
@@ -1026,7 +1026,7 @@
       next_frame_vpts += 1000;
     }
     
-    lprintf ("next_frame_vpts is %" PRId64 "\n", next_frame_vpts);
+    lprintf ("next_frame_vpts is %lld\n", next_frame_vpts);
  
     do {
       vpts = this->clock->get_current_time (this->clock);
@@ -1036,11 +1036,11 @@
 
       usec_to_sleep = (next_frame_vpts - vpts) * 100 / 9;
 
-      lprintf ("%" PRId64 " usec to sleep at master vpts %" PRId64 "\n", usec_to_sleep, vpts);
+      lprintf ("%lld usec to sleep at master vpts %lld\n", usec_to_sleep, vpts);
       
       if ( (next_frame_vpts - vpts) > 2*90000 )
         xprintf(this->xine, XINE_VERBOSITY_DEBUG,
-		"video_out: vpts/clock error, next_vpts=%" PRId64 " cur_vpts=%" PRId64 "\n", next_frame_vpts,vpts);
+		"video_out: vpts/clock error, next_vpts=%lld cur_vpts=%lld\n", next_frame_vpts,vpts);
                
       if (usec_to_sleep>0) 
 	xine_usec_sleep (usec_to_sleep);
