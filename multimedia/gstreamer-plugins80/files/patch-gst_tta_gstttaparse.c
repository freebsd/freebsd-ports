--- gst/tta/gstttaparse.c.orig	Sat Jan  8 13:36:26 2005
+++ gst/tta/gstttaparse.c	Sat Jan  8 13:37:08 2005
@@ -162,11 +162,14 @@
     case GST_EVENT_SEEK:
     {
       if (GST_EVENT_SEEK_FORMAT (event) == GST_FORMAT_TIME) {
-        GST_DEBUG_OBJECT (ttaparse, "got seek event");
         GstEvent *seek_event;
-        guint64 time = GST_EVENT_SEEK_OFFSET (event);
-        guint64 seek_frame = time / (FRAME_TIME * 1000000000);
-        guint64 seekpos = ttaparse->index[seek_frame].pos;
+	guint64 time;
+	guint64 seek_frame;
+	guint64 seekpos;
+        GST_DEBUG_OBJECT (ttaparse, "got seek event");
+        time = GST_EVENT_SEEK_OFFSET (event);
+        seek_frame = time / (FRAME_TIME * 1000000000);
+        seekpos = ttaparse->index[seek_frame].pos;
 
         GST_DEBUG_OBJECT (ttaparse, "seeking to %u", (guint) seekpos);
         seek_event =
