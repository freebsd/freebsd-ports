invalid suffix on literal; C++11 requires a space between literal and identifier 
[-Wreserved-user-defined-literal]
        GST_TRACE_OBJECT(m_sink, "Received buffer %"GST_PTR_FORMAT, bufEvent->buffer);

--- elements/gstqtvideosink/qtvideosinkdelegate.cpp.orig	2018-01-07 08:41:02 UTC
+++ elements/gstqtvideosink/qtvideosinkdelegate.cpp
@@ -376,7 +376,7 @@ bool QtVideoSinkDelegate::event(QEvent *event)
         BufferEvent *bufEvent = dynamic_cast<BufferEvent*>(event);
         Q_ASSERT(bufEvent);
 
-        GST_TRACE_OBJECT(m_sink, "Received buffer %"GST_PTR_FORMAT, bufEvent->buffer);
+        GST_TRACE_OBJECT(m_sink, "Received buffer %" GST_PTR_FORMAT, bufEvent->buffer);
 
         if (m_buffer) {
             //free the previous buffer
