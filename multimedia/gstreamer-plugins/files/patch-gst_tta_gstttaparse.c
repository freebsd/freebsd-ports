--- gst/tta/gstttaparse.c.orig	Sun Jan  9 13:59:02 2005
+++ gst/tta/gstttaparse.c	Sun Jan  9 14:02:25 2005
@@ -162,11 +162,13 @@
     case GST_EVENT_SEEK:
     {
       if (GST_EVENT_SEEK_FORMAT (event) == GST_FORMAT_TIME) {
-        GST_DEBUG_OBJECT (ttaparse, "got seek event");
         GstEvent *seek_event;
-        guint64 time = GST_EVENT_SEEK_OFFSET (event);
-        guint64 seek_frame = time / (FRAME_TIME * 1000000000);
-        guint64 seekpos = ttaparse->index[seek_frame].pos;
+        guint64 time;
+        guint64 seek_frame;
+        guint64 seekpos;
+        time = GST_EVENT_SEEK_OFFSET (event);
+        seek_frame = time / (FRAME_TIME * 1000000000);
+        seekpos = ttaparse->index[seek_frame].pos;
 
         GST_DEBUG_OBJECT (ttaparse, "seeking to %u", (guint) seekpos);
         seek_event =
