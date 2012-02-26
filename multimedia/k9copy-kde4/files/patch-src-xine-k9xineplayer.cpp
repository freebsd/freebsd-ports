--- src/xine/k9xineplayer.cpp.orig
+++ src/xine/k9xineplayer.cpp
@@ -260,8 +260,10 @@ void k9xinePlayer::init(WId _wid) {
     event_queue = xine_event_new_queue(stream);
     xine_event_create_listener_thread(event_queue, event_listener, this);
 
-    xine_gui_send_vo_data(stream, XINE_GUI_SEND_DRAWABLE_CHANGED, (void *) m_wid);
-    xine_gui_send_vo_data(stream, XINE_GUI_SEND_VIDEOWIN_VISIBLE, (void *) 1);
+    // xine_gui_send_vo_data(stream, XINE_GUI_SEND_DRAWABLE_CHANGED, (void *) m_wid);
+    // xine_gui_send_vo_data(stream, XINE_GUI_SEND_VIDEOWIN_VISIBLE, (void *) 1);
+    xine_port_send_gui_data(vo_port, XINE_GUI_SEND_DRAWABLE_CHANGED, (void *) m_wid);
+    xine_port_send_gui_data(vo_port, XINE_GUI_SEND_VIDEOWIN_VISIBLE, (void *) 1);
     m_execute=true;
 
 }
@@ -284,7 +286,8 @@ void k9xinePlayer::quit() {
 void k9xinePlayer::update() {
     if (stream && !running ) {
         if (m_mutex.tryLock()) {
-           xine_gui_send_vo_data(stream, XINE_GUI_SEND_DRAWABLE_CHANGED, (void *) m_wid);
+           // xine_gui_send_vo_data(stream, XINE_GUI_SEND_DRAWABLE_CHANGED, (void *) m_wid);
+           xine_port_send_gui_data(vo_port, XINE_GUI_SEND_DRAWABLE_CHANGED, (void *) m_wid);
            m_mutex.unlock();
         }
     }
@@ -317,7 +320,8 @@ void k9xineThread::run() {
         case Expose:
             if (xevent.xexpose.count != 0)
                 break;
-            xine_gui_send_vo_data(m_player->getStream(), XINE_GUI_SEND_EXPOSE_EVENT, &xevent);
+            // xine_gui_send_vo_data(m_player->getStream(), XINE_GUI_SEND_EXPOSE_EVENT, &xevent);
+            xine_port_send_gui_data(m_player->getPort(), XINE_GUI_SEND_EXPOSE_EVENT, &xevent);
             break;
         }
     }
