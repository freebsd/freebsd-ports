--- src/xine-engine/metronom.c.orig	Tue Apr  6 23:41:38 2004
+++ src/xine-engine/metronom.c	Tue Apr  6 23:44:02 2004
@@ -204,7 +204,7 @@
 static void metronom_start_clock (metronom_clock_t *this, int64_t pts) {
   scr_plugin_t** scr;
 
-  lprintf("start_clock (at %" PRId64 ")\n", pts);
+  lprintf("start_clock (at %lld)\n", pts);
 
   for (scr = this->scr_list; scr < this->scr_list+MAX_SCR_PROVIDERS; scr++)
     if (*scr) (*scr)->start(*scr, pts);
@@ -260,7 +260,7 @@
 
   pthread_mutex_unlock (&this->lock);
 
-  lprintf("%" PRId64 " pts per %d samples\n", pts_per_smpls, AUDIO_SAMPLE_NUM);
+  lprintf("%lld pts per %d samples\n", pts_per_smpls, AUDIO_SAMPLE_NUM);
 }
 
 static int64_t metronom_got_spu_packet (metronom_t *this, int64_t pts) {
@@ -314,7 +314,7 @@
       this->force_video_jump = 1;
       this->video_drift = 0;
       xprintf(this->xine, XINE_VERBOSITY_DEBUG,
-	      "vpts adjusted with prebuffer to %" PRId64 "\n", this->video_vpts);
+	      "vpts adjusted with prebuffer to %lld\n", this->video_vpts);
       break;
 
     case DISC_ABSOLUTE:
@@ -332,7 +332,7 @@
           this->force_video_jump = 1;
           this->force_audio_jump = 1;
           this->video_drift = 0;
-          xprintf(this->xine, XINE_VERBOSITY_DEBUG, "vpts adjusted with prebuffer to %" PRId64 "\n",
+          xprintf(this->xine, XINE_VERBOSITY_DEBUG, "vpts adjusted with prebuffer to %lld\n",
 	    this->video_vpts);
         }
       } else {
@@ -348,7 +348,7 @@
       break;
   }
 
-  lprintf("video_vpts: %" PRId64 ", audio_vpts: %" PRId64 "\n", this->video_vpts, this->audio_vpts);
+  lprintf("video_vpts: %lld, audio_vpts: %lld\n", this->video_vpts, this->audio_vpts);
 
   /* vpts_offset adjustements */
   switch (type) {
@@ -388,7 +388,7 @@
   this->video_discontinuity_count++;
   pthread_cond_signal (&this->video_discontinuity_reached);
   
-  xprintf(this->xine, XINE_VERBOSITY_DEBUG, "video discontinuity #%d, type is %d, disc_off %" PRId64 "\n",
+  xprintf(this->xine, XINE_VERBOSITY_DEBUG, "video discontinuity #%d, type is %d, disc_off %lld\n",
     this->video_discontinuity_count, type, disc_off);
   
   if (this->have_audio) {
@@ -449,7 +449,7 @@
     return;
   }
 
-  lprintf("got_video_frame pts = %" PRId64 ", duration = %d\n", pts, img->duration);
+  lprintf("got_video_frame pts = %lld, duration = %d\n", pts, img->duration);
 
   this->img_cpt++;
 
@@ -462,7 +462,7 @@
     if (!img->duration) {
       if (this->last_video_pts && this->img_cpt) {
         this->img_duration = (pts - this->last_video_pts) / this->img_cpt;
-        lprintf("computed frame_duration = %" PRId64 "\n", this->img_duration );
+        lprintf("computed frame_duration = %lld\n", this->img_duration );
       }
       img->duration = this->img_duration;
     } else {
@@ -483,7 +483,7 @@
 
     diff = this->video_vpts - vpts;
 
-    lprintf("video diff is %" PRId64 " (predicted %" PRId64 ", given %" PRId64 ")\n", diff, this->video_vpts, vpts);
+    lprintf("video diff is %lld (predicted %lld, given %lld)\n", diff, this->video_vpts, vpts);
 
     if ((abs (diff) > VIDEO_DRIFT_TOLERANCE) || (this->force_video_jump)) {
       this->force_video_jump = 0;
@@ -499,7 +499,7 @@
       /* this will fix video drift with a constant compensation each
 	 frame for about 1 second of video.  */
 
-      if (diff) lprintf("video drift, drift is %" PRId64 "\n", this->video_drift);
+      if (diff) lprintf("video drift, drift is %lld\n", this->video_drift);
     }
   } else {
     if (!img->duration) {
@@ -512,7 +512,7 @@
   
   img->vpts = this->video_vpts + this->av_offset;
 
-  lprintf("video vpts for %10lld : %10lld (duration:%d drift:%" PRId64 " step:%" PRId64 ")\n", 
+  lprintf("video vpts for %10lld : %10lld (duration:%d drift:%lld step:%lld)\n", 
 	  pts, this->video_vpts, img->duration, this->video_drift, this->video_drift_step );
   
   if( this->video_drift * this->video_drift_step > 0 )
@@ -541,7 +541,7 @@
   this->audio_discontinuity_count++;
   pthread_cond_signal (&this->audio_discontinuity_reached);
   
-  xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio discontinuity #%d, type is %d, disc_off %" PRId64 "\n",
+  xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio discontinuity #%d, type is %d, disc_off %lld\n",
 	  this->audio_discontinuity_count, type, disc_off);
 
   if (this->have_video) {
@@ -571,8 +571,8 @@
   int64_t vpts;
   int64_t diff;
 
-  lprintf("got %d audio samples, pts is %" PRId64 ", last pts = %" PRId64 "\n", nsamples, pts, this->last_audio_pts);
-  lprintf("AUDIO pts from last= %" PRId64 "\n", pts-this->last_audio_pts);
+  lprintf("got %d audio samples, pts is %lld, last pts = %lld\n", nsamples, pts, this->last_audio_pts);
+  lprintf("AUDIO pts from last= %lld\n", pts-this->last_audio_pts);
 
   pthread_mutex_lock (&this->lock);
   
@@ -616,11 +616,11 @@
       this->force_audio_jump = 0;
       this->audio_vpts       = vpts;
       this->audio_drift_step = 0;
-      xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio jump, diff=%" PRId64 "\n", diff);
+      xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio jump, diff=%lld\n", diff);
     } else {
       if( this->audio_samples ) {
         /* calculate drift_step to recover vpts errors */
-        lprintf("audio diff = %" PRId64 " \n", diff );
+        lprintf("audio diff = %lld \n", diff );
 
         diff *= AUDIO_SAMPLE_NUM;
         diff /= this->audio_samples * 4;
@@ -633,7 +633,7 @@
         
         this->audio_drift_step = diff;
                 
-        lprintf("audio_drift = %" PRId64 ", pts_per_smpls = %" PRId64 "\n", diff, this->pts_per_smpls);
+        lprintf("audio_drift = %lld, pts_per_smpls = %lld\n", diff, this->pts_per_smpls);
       }
     }
     this->audio_samples = 0;
@@ -671,11 +671,11 @@
   switch (option) {
   case METRONOM_AV_OFFSET:
     this->av_offset = value;
-    xprintf(this->xine, XINE_VERBOSITY_LOG, "av_offset=%" PRId64 " pts\n", this->av_offset);
+    xprintf(this->xine, XINE_VERBOSITY_LOG, "av_offset=%lld pts\n", this->av_offset);
     break;
   case METRONOM_SPU_OFFSET:
     this->spu_offset = value;
-    xprintf(this->xine, XINE_VERBOSITY_LOG, "spu_offset=%" PRId64 " pts\n", this->spu_offset);
+    xprintf(this->xine, XINE_VERBOSITY_LOG, "spu_offset=%lld pts\n", this->spu_offset);
     break;
   case METRONOM_ADJ_VPTS_OFFSET:
     this->audio_vpts += value;
@@ -685,11 +685,11 @@
      * once in a while means a small sound card drift (or system
      * clock drift -- who knows?). nothing to worry about.
      */
-    xprintf(this->xine, XINE_VERBOSITY_LOG, "fixing sound card drift by %" PRId64 " pts\n", value);
+    xprintf(this->xine, XINE_VERBOSITY_LOG, "fixing sound card drift by %lld pts\n", value);
     break;
   case METRONOM_PREBUFFER:
     this->prebuffer = value;
-    xprintf(this->xine, XINE_VERBOSITY_LOG, "prebuffer=%" PRId64 " pts\n", this->prebuffer);
+    xprintf(this->xine, XINE_VERBOSITY_LOG, "prebuffer=%lld pts\n", this->prebuffer);
     break;
   default:
     xprintf(this->xine, XINE_VERBOSITY_NONE, "unknown option in set_option: %d\n", option);
