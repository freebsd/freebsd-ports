--- src/demuxers/demux_ogg.c.orig	Wed Apr  7 23:14:21 2004
+++ src/demuxers/demux_ogg.c	Wed Apr  7 23:15:31 2004
@@ -321,7 +321,7 @@
 static void check_newpts (demux_ogg_t *this, int64_t pts, int video, int preview) {
   int64_t diff;
 
-  lprintf ("new pts %" PRId64 " found in stream\n",pts);
+  lprintf ("new pts %lld found in stream\n",pts);
 
   diff = pts - this->last_pts[video];
 
@@ -329,7 +329,7 @@
       (this->send_newpts || (this->last_pts[video] && abs(diff)>WRAP_THRESHOLD) ) ) {
 
     xprintf (this->stream->xine, XINE_VERBOSITY_DEBUG,
-             "diff=%" PRId64 " (pts=%" PRId64 ", last_pts=%" PRId64 ")\n", diff, pts, this->last_pts[video]);
+             "diff=%lld (pts=%lld, last_pts=%lld)\n", diff, pts, this->last_pts[video]);
 
     if (this->buf_flag_seek) {
       _x_demux_control_newpts(this->stream, pts, BUF_FLAG_SEEK);
@@ -576,7 +576,7 @@
     } else
       pts = 0;
 
-    lprintf ("audiostream %d op-gpos %" PRId64 " hdr-gpos %" PRId64 " pts %" PRId64 " \n",
+    lprintf ("audiostream %d op-gpos %lld hdr-gpos %lld pts %lld \n",
              stream_num,
              op->granulepos,
              this->si[stream_num]->header_granulepos,
@@ -611,7 +611,7 @@
     } else
       pts = 0;
 
-    lprintf ("theorastream %d op-gpos %" PRId64 " hdr-gpos %" PRId64 " pts %" PRId64 " \n",
+    lprintf ("theorastream %d op-gpos %lld hdr-gpos %lld pts %lld \n",
              stream_num,
              op->granulepos,
              this->si[stream_num]->header_granulepos,
@@ -643,7 +643,7 @@
       } else
         pts = 0;
       
-      lprintf ("videostream %d op-gpos %" PRId64 " hdr-gpos %" PRId64 " pts %" PRId64 " \n",
+      lprintf ("videostream %d op-gpos %lld hdr-gpos %lld pts %lld \n",
                stream_num,
                op->granulepos,
                this->si[stream_num]->header_granulepos,
@@ -819,8 +819,8 @@
   this->si[stream_num]->headers = 0; /* header is sent below */
 
   lprintf ("subtype          %.4s\n", (char*)&locsubtype);
-  lprintf ("time_unit        %" PRId64 "\n", loctime_unit);
-  lprintf ("samples_per_unit %" PRId64 "\n", locsamples_per_unit);
+  lprintf ("time_unit        %lld\n", loctime_unit);
+  lprintf ("samples_per_unit %lld\n", locsamples_per_unit);
   lprintf ("default_len      %d\n", locdefault_len);
   lprintf ("buffersize       %d\n", locbuffersize);
   lprintf ("bits_per_sample  %d\n", locbits_per_sample);
@@ -906,8 +906,8 @@
     }
 
     lprintf ("subtype          0x%x\n", codec);
-    lprintf ("time_unit        %" PRId64 "\n", loctime_unit);
-    lprintf ("samples_per_unit %" PRId64 "\n", locsamples_per_unit);
+    lprintf ("time_unit        %lld\n", loctime_unit);
+    lprintf ("samples_per_unit %lld\n", locsamples_per_unit);
     lprintf ("default_len      %d\n", locdefault_len);
     lprintf ("buffersize       %d\n", locbuffersize);
     lprintf ("bits_per_sample  %d\n", locbits_per_sample);
@@ -1322,7 +1322,7 @@
           iframe=op.granulepos>>keyframe_granule_shift;
           pframe=op.granulepos-(iframe<<keyframe_granule_shift);
           xprintf (this->stream->xine, XINE_VERBOSITY_DEBUG,
-                   "seeking keyframe i %" PRId64 " p %" PRId64 "\n", iframe, pframe);
+                   "seeking keyframe i %lld p %lld\n", iframe, pframe);
           if (pframe!=0)
             continue;
         } else
@@ -1426,7 +1426,7 @@
   if (this->status == DEMUX_OK) {
     _x_demux_control_start(this->stream);
     send_header (this);
-    lprintf ("headers sent, avg bitrate is %" PRId64 "\n", this->avg_bitrate);
+    lprintf ("headers sent, avg bitrate is %lld\n", this->avg_bitrate);
   }
 
   _x_stream_info_set(this->stream, XINE_STREAM_INFO_HAS_VIDEO,
@@ -1489,15 +1489,15 @@
 	    );
 	}
 
-	lprintf ("current_pos is %" PRId64 "\n",current_pos);
-	lprintf ("new_pos is %" PRId64 "\n",start_pos); 
+	lprintf ("current_pos is %lld\n",current_pos);
+	lprintf ("new_pos is %lld\n",start_pos); 
 
       } else {
 	/*seek using avg_bitrate*/
 	start_pos = start_time * this->avg_bitrate/8;
       }
 
-      lprintf ("seeking to %d seconds => %" PRId64 " bytes\n",
+      lprintf ("seeking to %d seconds => %lld bytes\n",
 	      start_time, start_pos);
 
     }
@@ -1513,7 +1513,7 @@
     if (start_pos == 0)	 
       this->keyframe_needed = 0;	 
 
-    lprintf ("seek to %" PRId64 " called\n",start_pos);
+    lprintf ("seek to %lld called\n",start_pos);
 
     this->input->seek (this->input, start_pos, SEEK_SET);
 
