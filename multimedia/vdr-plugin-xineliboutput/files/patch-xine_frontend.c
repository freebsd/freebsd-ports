--- a/xine_frontend.c.orig	2012-05-11 07:37:27 UTC
+++ b/xine_frontend.c
@@ -25,7 +25,6 @@
 # undef boolean
 #endif
 
-#define XINE_ENGINE_INTERNAL
 #include <xine.h>
 #include <xine/xine_internal.h>
 
@@ -1702,13 +1701,16 @@ static vo_frame_t *yuy2_to_yv12_frame(xine_stream_t *s
 {
   /* convert yuy12 frames to yv12 */
   if (frame && frame->format == XINE_IMGFMT_YUY2) {
-    stream->xine->port_ticket->acquire(stream->xine->port_ticket, 0);
-    vo_frame_t *img = stream->video_out->get_frame (stream->video_out,
-                                                    frame->width, frame->height,
-                                                    frame->ratio, XINE_IMGFMT_YV12,
-                                                    VO_BOTH_FIELDS);
-    stream->xine->port_ticket->release(stream->xine->port_ticket, 0);
+    vo_frame_t *img = NULL;
 
+    if (_x_lock_port_rewiring(stream->xine, 0)) {
+      img = stream->video_out->get_frame (stream->video_out,
+                                          frame->width, frame->height,
+                                          frame->ratio, XINE_IMGFMT_YV12,
+                                          VO_BOTH_FIELDS);
+      _x_unlock_port_rewiring(stream->xine);
+    }
+
     if (!img) {
       LOGMSG("yuy2_to_yv12_frame: get_frame failed");
       frame->free(frame);
@@ -1738,6 +1740,8 @@ static char *frame_compress_jpeg(fe_t *this, int *size
 
   /* convert yuy2 frames to yv12 */
   frame = yuy2_to_yv12_frame(this->stream, frame);
+  if (!frame)
+    return NULL;
 
   /* Compress JPEG */
 
@@ -1836,13 +1840,16 @@ static vo_frame_t *yv12_to_yuy2_frame(xine_stream_t *s
 {
   /* convert yv12 frames to yuy2 */
   if (frame && frame->format == XINE_IMGFMT_YV12) {
-    stream->xine->port_ticket->acquire(stream->xine->port_ticket, 0);
-    vo_frame_t *img = stream->video_out->get_frame (stream->video_out,
-                                                    frame->width, frame->height,
-                                                    frame->ratio, XINE_IMGFMT_YUY2,
-                                                    VO_BOTH_FIELDS);
-    stream->xine->port_ticket->release(stream->xine->port_ticket, 0);
+    vo_frame_t *img = NULL;
 
+    if (_x_lock_port_rewiring(stream->xine, 0)) {
+      img = stream->video_out->get_frame (stream->video_out,
+                                          frame->width, frame->height,
+                                          frame->ratio, XINE_IMGFMT_YUY2,
+                                          VO_BOTH_FIELDS);
+      _x_unlock_port_rewiring(stream->xine);
+    }
+
     if (!img) {
       LOGMSG("yv12_to_yuy2_frame: get_frame failed");
       frame->free(frame);
@@ -2006,11 +2013,16 @@ static char *fe_grab(frontend_t *this_gen, int *size, 
   height = (MAX(16, MIN(height, 1200)) + 1) & ~1; /* 16...1200, even */
 
   /* get last frame */
-  this->stream->xine->port_ticket->acquire(this->stream->xine->port_ticket, 0);
 
 #ifdef HAVE_XINE_GRAB_VIDEO_FRAME
+  xine_grab_video_frame_t *grab_frame = NULL;
   char *img = NULL;
-  xine_grab_video_frame_t *grab_frame = xine_new_grab_video_frame(this->stream);
+
+  if (_x_lock_port_rewiring(this->xine, 0)) {
+    grab_frame = xine_new_grab_video_frame(this->stream);
+    _x_unlock_port_rewiring(this->xine);
+  }
+
   if (grab_frame) {
     grab_frame->width = width;
     grab_frame->height = height;
@@ -2018,15 +2030,18 @@ static char *fe_grab(frontend_t *this_gen, int *size, 
       img = fe_compress_grab_frame(this, size, jpeg, quality, width, height, grab_frame);
     grab_frame->dispose(grab_frame);
   }
-  this->stream->xine->port_ticket->release(this->stream->xine->port_ticket, 0);
   return img;
 #else
-  vo_frame_t *frame = this->stream->video_out->get_last_frame (this->stream->video_out);
+  vo_frame_t *frame = NULL;
+
+  if (_x_lock_port_rewiring(this->xine, 0)) {
+    frame = this->stream->video_out->get_last_frame (this->stream->video_out);
 #if XINE_VERSION_CODE < 10190
-  if(frame)
-    frame->lock(frame);
+    if (frame)
+      frame->lock(frame);
 #endif
-  this->stream->xine->port_ticket->release(this->stream->xine->port_ticket, 0);
+    _x_unlock_port_rewiring(this->xine);
+  }
 
   if(!frame) {
     LOGMSG("fe_grab: get_last_frame() failed");
