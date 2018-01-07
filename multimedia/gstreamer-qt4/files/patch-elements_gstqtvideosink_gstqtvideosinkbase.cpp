invalid suffix on literal; C++11 requires a space between literal and identifier 
[-Wreserved-user-defined-literal]
    GST_TRACE_OBJECT(sink, "Posting new buffer (%"GST_PTR_FORMAT") for rendering. "

--- elements/gstqtvideosink/gstqtvideosinkbase.cpp.orig	2018-01-07 08:43:35 UTC
+++ elements/gstqtvideosink/gstqtvideosinkbase.cpp
@@ -217,7 +217,7 @@ GstFlowReturn GstQtVideoSinkBase::show_frame(GstVideoS
 {
     GstQtVideoSinkBase *sink = GST_QT_VIDEO_SINK_BASE(video_sink);
 
-    GST_TRACE_OBJECT(sink, "Posting new buffer (%"GST_PTR_FORMAT") for rendering. "
+    GST_TRACE_OBJECT(sink, "Posting new buffer (%" GST_PTR_FORMAT ") for rendering. "
                            "Format dirty: %d", buffer, (int)sink->formatDirty);
 
     QCoreApplication::postEvent(sink->delegate,
