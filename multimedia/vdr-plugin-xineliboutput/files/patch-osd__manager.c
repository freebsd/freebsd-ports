--- a/xine/osd_manager.c.orig	2012-05-11 07:37:27 UTC
+++ b/xine/osd_manager.c
@@ -11,7 +11,6 @@
 #include <stdlib.h>
 #include <pthread.h>
 
-#define XINE_ENGINE_INTERNAL
 #include <xine/xine_internal.h>
 #include <xine/video_out.h>
 
@@ -70,18 +69,25 @@ typedef struct osd_manager_impl_s {
 /*
  * acquire_ticket()
  */
-static void acquire_ticket(osd_manager_impl_t *this)
+static int acquire_ticket(osd_manager_impl_t *this)
 {
-  if (!this->ticket_acquired) {
-    this->stream->xine->port_ticket->acquire(this->stream->xine->port_ticket, 1);
+  if (this->ticket_acquired) {
+    return 1;
+  }
+
+  if (_x_lock_port_rewiring(this->stream->xine, 200)) {
     this->ticket_acquired = 1;
+    return 1;
   }
+
+  LOGMSG("lock_port_rewiring() failed");
+  return 0;
 }
 
 static void release_ticket(osd_manager_impl_t *this)
 {
   if (this->ticket_acquired) {
-    this->stream->xine->port_ticket->release(this->stream->xine->port_ticket, 1);
+    _x_unlock_port_rewiring(this->stream->xine);
     this->ticket_acquired = 0;
   }
 }
@@ -92,7 +98,10 @@ static void release_ticket(osd_manager_impl_t *this)
 video_overlay_manager_t *get_ovl_manager(osd_manager_impl_t *this)
 {
   /* Get overlay manager. We need ticket ... */
-  acquire_ticket(this);
+
+  if (!acquire_ticket(this))
+    return NULL;
+
   video_overlay_manager_t *ovl_manager = this->stream->video_out->get_overlay_manager(this->stream->video_out);
   if (!ovl_manager) {
     LOGMSG("Stream has no overlay manager !");
@@ -256,7 +265,10 @@ static int exec_osd_size(osd_manager_impl_t *this, osd
   osd->video_window_w = 0;
   osd->video_window_h = 0;
 
-  acquire_ticket(this);
+  if (!acquire_ticket(this)) {
+    return CONTROL_PARAM_ERROR;
+  }
+
 
   xine_video_port_t *video_out = this->stream->video_out;
 
