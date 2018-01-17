error: invalid suffix on literal; C++11 requires a space between literal and identifier 
[-Wreserved-user-defined-literal]
    GST_LOG_OBJECT(m_sink, "Setting \"widget\" property to %"GST_PTR_FORMAT, widget);

--- elements/gstqtvideosink/qwidgetvideosinkdelegate.cpp.orig	2018-01-07 08:41:23 UTC
+++ elements/gstqtvideosink/qwidgetvideosinkdelegate.cpp
@@ -36,7 +36,7 @@ QWidget *QWidgetVideoSinkDelegate::widget() const
 
 void QWidgetVideoSinkDelegate::setWidget(QWidget *widget)
 {
-    GST_LOG_OBJECT(m_sink, "Setting \"widget\" property to %"GST_PTR_FORMAT, widget);
+    GST_LOG_OBJECT(m_sink, "Setting \"widget\" property to %" GST_PTR_FORMAT, widget);
 
     if (m_widget) {
         m_widget.data()->removeEventFilter(this);
