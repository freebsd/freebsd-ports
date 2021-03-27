--- xine_input_vdr.c.orig	2012-05-11 07:37:27 UTC
+++ xine_input_vdr.c
@@ -1573,9 +1573,7 @@ static void set_still_mode(vdr_input_plugin_t *this, i
   if (still_mode || this->still_mode)
     CHECK_FALSE(this->live_mode);
 
-  pthread_mutex_lock (&this->stream->first_frame_lock);
-  this->stream->first_frame_flag = 2;
-  pthread_mutex_unlock (&this->stream->first_frame_lock);
+  _x_trigger_relaxed_frame_drop_mode(this->stream);
 
   this->still_mode = !!still_mode;
   _x_stream_info_set(this->stream, XINE_STREAM_INFO_VIDEO_HAS_STILL, this->still_mode);
@@ -1719,11 +1717,12 @@ static void queue_blank_yv12(vdr_input_plugin_t *this)
   _x_demux_control_newpts(this->stream, 0, BUF_FLAG_SEEK);
 
 
-  this->class->xine->port_ticket->acquire (this->class->xine->port_ticket, 1);
-  img = this->stream->video_out->get_frame (this->stream->video_out,
-                                            width, height, dratio,
-                                            XINE_IMGFMT_YV12, VO_BOTH_FIELDS);
-  this->class->xine->port_ticket->release (this->class->xine->port_ticket, 1);
+  if (_x_lock_port_rewiring(this->class->xine, 100)) {
+    img = this->stream->video_out->get_frame (this->stream->video_out,
+                                              width, height, dratio,
+                                              XINE_IMGFMT_YV12, VO_BOTH_FIELDS);
+    _x_unlock_port_rewiring(this->class->xine);
+  }
 
   if (img) {
     if (img->format == XINE_IMGFMT_YV12 && img->base[0] && img->base[1] && img->base[2]) {
@@ -1977,88 +1976,6 @@ static int vdr_plugin_exec_osd_command(vdr_input_plugi
 
 /******************************* Control *********************************/
 
-#if XINE_VERSION_CODE < 10111
-# define DEMUX_MUTEX_LOCK
-# define DEMUX_MUTEX_UNLOCK
-# define DEMUX_RESUME_SIGNAL
-#else
-# define DEMUX_MUTEX_LOCK    pthread_mutex_lock(&stream->demux_mutex)
-# define DEMUX_MUTEX_UNLOCK  pthread_mutex_unlock(&stream->demux_mutex)
-# define DEMUX_RESUME_SIGNAL pthread_cond_signal(&this->stream->demux_resume)
-#endif
-
-#if XINE_VERSION_CODE < 10200
-# define RAISE_ACTION_PENDING this->stream->demux_action_pending = 1
-# define LOWER_ACTION_PENDING this->stream->demux_action_pending = 0
-#else
-# define RAISE_ACTION_PENDING _x_action_raise(this->stream)
-# define LOWER_ACTION_PENDING _x_action_lower(this->stream)
-#endif
-
-static void suspend_demuxer(vdr_input_plugin_t *this)
-{
-  if (this->is_paused)
-    LOGMSG("WARNING: called suspend_demuxer in paused mode !");
-
-  /* request demuxer to release demux_lock */
-  RAISE_ACTION_PENDING;
-
-  /* signal all possible sync points to speed up this */
-  pthread_cond_broadcast(&this->engine_flushed);
-  signal_buffer_not_empty(this);
-
-  /* let demuxer return from vdr_plugin_read_* */
-  if (pthread_mutex_unlock( &this->lock ))
-    LOGERR("pthread_mutex_unlock failed !");
-
-  /* lock demuxer */
-  pthread_mutex_lock( &this->stream->demux_lock );
-
-  LOWER_ACTION_PENDING;
-
-  pthread_mutex_lock( &this->lock );
-
-  /* must be paired with resume_demuxer !!! */
-}
-
-static void resume_demuxer(vdr_input_plugin_t *this)
-{
-  /* must be paired with suspend_demuxer !!! */
-
-  DEMUX_RESUME_SIGNAL;
-  pthread_mutex_unlock( &this->stream->demux_lock );
-}
-
-static void vdr_x_demux_control_newpts( xine_stream_t *stream, int64_t pts, 
-					uint32_t flags ) 
-{
-  buf_element_t *buf;
-
-  DEMUX_MUTEX_LOCK;
-
-  buf = stream->video_fifo ? stream->video_fifo->buffer_pool_try_alloc (stream->video_fifo) : NULL;
-  if(buf) {
-    buf->type = BUF_CONTROL_NEWPTS;
-    buf->decoder_flags = flags;
-    buf->disc_off = pts;
-    stream->video_fifo->put (stream->video_fifo, buf); 
-  } else {
-    LOGMSG("vdr_x_demux_control_newpts: video fifo full !");
-  }
-
-  buf = stream->audio_fifo ? stream->audio_fifo->buffer_pool_try_alloc (stream->audio_fifo) : NULL;
-  if (buf) {
-    buf->type = BUF_CONTROL_NEWPTS;
-    buf->decoder_flags = flags;
-    buf->disc_off = pts;
-    stream->audio_fifo->put (stream->audio_fifo, buf);
-  } else {
-    LOGMSG("vdr_x_demux_control_newpts: audio fifo full !");
-  }
-
-  DEMUX_MUTEX_UNLOCK;
-}
-
 static void vdr_flush_engine(vdr_input_plugin_t *this, uint64_t discard_index)
 {
   CHECK_LOCKED(this->lock);
@@ -2078,44 +1995,30 @@ static void vdr_flush_engine(vdr_input_plugin_t *this,
     return;
   }
 
+  if (this->is_paused)
+    LOGMSG("WARNING: called suspend_demuxer in paused mode !");
+
   /* reset speed */
+  reset_scr_tuning(this);
   if(xine_get_param(this->stream, XINE_PARAM_FINE_SPEED) <= 0) {
     LOGMSG("vdr_flush_engine: playback is paused <0>");
     xine_set_param(this->stream, XINE_PARAM_FINE_SPEED, XINE_FINE_SPEED_NORMAL);
   }
 
-  /* suspend demuxer */
-  suspend_demuxer(this);
+  pthread_mutex_unlock(&this->lock);
 
-  reset_scr_tuning(this);
+  _x_demux_seek(this->stream, 0, 0, 1);
+  pthread_mutex_lock(&this->lock);
 
-  /* reset speed again (adjust_realtime_speed might have set pause) */
-  if(xine_get_param(this->stream, XINE_PARAM_FINE_SPEED) <= 0) {
-    LOGMSG("vdr_flush_engine: playback is paused <1>");
-    xine_set_param(this->stream, XINE_PARAM_FINE_SPEED, XINE_FINE_SPEED_NORMAL);
-  }
-
-#if 0
-  _x_demux_flush_engine (this->stream);
-  /* warning: after clearing decoders fifos an absolute discontinuity
-   *          indication must be sent. relative discontinuities are likely
-   *          to cause "jumps" on metronom.
-   */
-#else
-  this->stream->demux_plugin->seek (this->stream->demux_plugin,
-				    0, 0, this->stream->demux_thread_running);
-#endif
-
 #if XINE_VERSION_CODE < 10104
   /* disabled _x_demux_control_start as it causes alsa output driver to exit now and then ... */
 #else
   _x_demux_control_start(this->stream);
 #endif
+
+reset_scr_tuning(this);
   this->stream_start = 1;
   this->I_frames = this->B_frames = this->P_frames = 0;
-  this->discard_index = discard_index;
-
-  resume_demuxer(this);
 }
 
 static int set_deinterlace_method(vdr_input_plugin_t *this, const char *method_name)
@@ -2327,13 +2230,14 @@ static void select_spu_channel(xine_stream_t *stream, 
   if (channel == SPU_CHANNEL_NONE) {
     /* re-enable overlay for VDR OSD ... */
     if (stream->video_out) {
-      pthread_mutex_lock (&stream->frontend_lock);
-      stream->xine->port_ticket->acquire (stream->xine->port_ticket, 0);
-    
-      stream->video_out->enable_ovl (stream->video_out, 1);
+      //pthread_mutex_lock (&stream->frontend_lock);
 
-      stream->xine->port_ticket->release (stream->xine->port_ticket, 0);
-      pthread_mutex_unlock (&stream->frontend_lock);
+      if (_x_lock_port_rewiring(stream->xine, 100)) {
+        stream->video_out->enable_ovl (stream->video_out, 1);
+        _x_unlock_port_rewiring(stream->xine);
+      }
+
+      //pthread_mutex_unlock (&stream->frontend_lock);
     }
   }
 }
@@ -2957,12 +2861,13 @@ static int vdr_plugin_flush(vdr_input_plugin_t *this, 
     return 1; 
   }
 
-  this->class->xine->port_ticket->acquire(this->class->xine->port_ticket, 1);
-  result = MAX(0, pool->size(pool)) + 
-           MAX(0, buffer->size(buffer)) +
-           this->stream->video_out->get_property(this->stream->video_out, 
-						 VO_PROP_BUFS_IN_FIFO);
-  this->class->xine->port_ticket->release(this->class->xine->port_ticket, 1);
+  if (_x_lock_port_rewiring(this->class->xine, 100)) {
+    result = MAX(0, pool->size(pool)) +
+        MAX(0, buffer->size(buffer)) +
+        this->stream->video_out->get_property(this->stream->video_out,
+                                              VO_PROP_BUFS_IN_FIFO);
+    _x_unlock_port_rewiring(this->class->xine);
+  }
 
   put_control_buf(buffer, pool, BUF_CONTROL_FLUSH_DECODER);
   put_control_buf(buffer, pool, BUF_CONTROL_NOP);
@@ -2985,12 +2890,14 @@ static int vdr_plugin_flush(vdr_input_plugin_t *this, 
 					 &pool->buffer_pool_mutex, &abstime);
     pthread_mutex_unlock(&pool->buffer_pool_mutex);
 
-    this->class->xine->port_ticket->acquire(this->class->xine->port_ticket, 1);
-    result = MAX(0, pool->size(pool)) +
-             MAX(0, buffer->size(buffer)) +
-             this->stream->video_out->get_property(this->stream->video_out, 
-						   VO_PROP_BUFS_IN_FIFO);
-    this->class->xine->port_ticket->release(this->class->xine->port_ticket, 1);
+    result = 0;
+    if (_x_lock_port_rewiring(this->class->xine, 100)) {
+      result = MAX(0, pool->size(pool)) +
+          MAX(0, buffer->size(buffer)) +
+          this->stream->video_out->get_property(this->stream->video_out,
+                                                VO_PROP_BUFS_IN_FIFO);
+      _x_unlock_port_rewiring(this->class->xine);
+    }
   }
 
   TRACE("vdr_plugin_flush returns %d (%d+%d used, %d frames)\n", result,
@@ -4775,7 +4682,6 @@ static buf_element_t *preprocess_buf(vdr_input_plugin_
 	     this->block_buffer->fifo_size,
 	     this->stream->video_fifo->fifo_size);
     } else {
-      vdr_x_demux_control_newpts(this->stream, 0, BUF_FLAG_SEEK);
       queue_blank_yv12(this);
     }
     pthread_mutex_unlock(&this->lock);
@@ -4815,9 +4721,7 @@ static buf_element_t *preprocess_buf(vdr_input_plugin_
   /* First packet ? */
   if (this->stream_start) {
     this->stream_start = 0;
-    pthread_mutex_lock (&this->stream->first_frame_lock);
-    this->stream->first_frame_flag = 2;
-    pthread_mutex_unlock (&this->stream->first_frame_lock);
+    _x_trigger_relaxed_frame_drop_mode(this->stream);
 
     memset(&this->scr_buf, 0, sizeof(this->scr_buf));
 
@@ -4900,7 +4804,9 @@ static void handle_disconnect(vdr_input_plugin_t *this
   reset_trick_speed(this);
   this->live_mode = 0;
   reset_scr_tuning(this);
+#if XINE_VERSION_CODE < 10209
   this->stream->emergency_brake = 1;
+#endif
 
   this->control_running = 0;
   errno = ENOTCONN;
@@ -5869,11 +5775,12 @@ static int vdr_plugin_open_net (input_plugin_t *this_g
     return 0;
   }
 
-  this->class->xine->port_ticket->acquire(this->class->xine->port_ticket, 1);
-  if(!(this->stream->video_out->get_capabilities(this->stream->video_out) &
-       VO_CAP_UNSCALED_OVERLAY))
-    LOGMSG("WARNING: Video output driver reports it does not support unscaled overlays !");
-  this->class->xine->port_ticket->release(this->class->xine->port_ticket, 1);
+  if (_x_lock_port_rewiring(this->class->xine, 0)) {
+    if(!(this->stream->video_out->get_capabilities(this->stream->video_out) &
+         VO_CAP_UNSCALED_OVERLAY))
+      LOGMSG("WARNING: Video output driver reports it does not support unscaled overlays !");
+    _x_unlock_port_rewiring(this->class->xine);
+  }
 
   this->threads_initialized = 1;
   return 1;
