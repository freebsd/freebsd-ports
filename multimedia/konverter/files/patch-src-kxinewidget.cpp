--- src/kxinewidget.cpp.orig
+++ src/kxinewidget.cpp
@@ -885,7 +885,8 @@ void KXineWidget::run()
      {
        if (event.xexpose.count == 0)
        {
-         xine_gui_send_vo_data (m_xineStream, XINE_GUI_SEND_EXPOSE_EVENT, &event);
+         // xine_gui_send_vo_data (m_xineStream, XINE_GUI_SEND_EXPOSE_EVENT, &event);
+         xine_port_send_gui_data (m_videoDriver, XINE_GUI_SEND_EXPOSE_EVENT, &event);
        }
      }
         
@@ -1775,7 +1776,11 @@ void KXineWidget::getAutoplayPlugins(QSt
 
 bool KXineWidget::getAutoplayPluginURLS(const QString& plugin, QStringList& list)
 {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
   char** urls = NULL;
+#else
+  const char* const* urls = NULL;
+#endif
   int num;
   int i = 0;
 
@@ -1859,7 +1864,10 @@ void KXineWidget::mouseMoveEvent(QMouseE
     rect.w = 0;
     rect.h = 0;
 
-    xine_gui_send_vo_data(m_xineStream,
+    // xine_gui_send_vo_data(m_xineStream,
+    //            XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO,
+    //             (void*)&rect);
+    xine_port_send_gui_data(m_videoDriver,
                XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO,
                 (void*)&rect);
 
@@ -1913,7 +1921,10 @@ void KXineWidget::mousePressEvent(QMouse
      rect.w = 0;
      rect.h = 0;
 
-     xine_gui_send_vo_data (m_xineStream,
+     // xine_gui_send_vo_data (m_xineStream,
+     //            XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO,
+     //               (void*)&rect);
+     xine_port_send_gui_data(m_videoDriver,
                 XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO,
                    (void*)&rect);
 
