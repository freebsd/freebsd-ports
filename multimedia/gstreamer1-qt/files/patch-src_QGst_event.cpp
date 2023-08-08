--- src/QGst/event.cpp.orig	2014-07-08 18:38:36 UTC
+++ src/QGst/event.cpp
@@ -125,7 +125,7 @@ Segment SegmentEvent::segment() const
 //********************************************************
 TagEventPtr TagEvent::create(const TagList & taglist)
 {
-    GstEvent * e = gst_event_new_tag(gst_tag_list_copy(taglist));
+    GstEvent * e = gst_event_new_tag(gst_tag_list_copy(&taglist));
     return TagEventPtr::wrap(e, false);
 }
 
