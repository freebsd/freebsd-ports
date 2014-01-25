--- src/xine/k9xineplayer.cpp.orig	2009-12-06 10:13:37.000000000 +0000
+++ src/xine/k9xineplayer.cpp	2013-12-06 15:34:35.000000000 +0000
@@ -251,7 +251,7 @@
 
     if ((vo_port = xine_open_video_driver(xine,
                                           m_vo.toAscii(), XINE_VISUAL_TYPE_X11, (void *) &vis)) == NULL) {
-        printf("I'm unable to initialize '%s' video driver. Giving up.\n", m_vo.toAscii());
+        printf("I'm unable to initialize '%s' video driver. Giving up.\n", m_vo.toAscii().constData());
         return ;
     }
 
@@ -260,8 +260,10 @@
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
@@ -270,7 +272,7 @@
     running=false;
     m_title="";
     if ((!xine_open(stream, m_mrl.toUtf8())) || (!xine_play(stream, 0, 0))) {
-        printf("Unable to open mrl '%s'\n", m_mrl.toUtf8());
+        printf("Unable to open mrl '%s'\n", m_mrl.toUtf8().constData());
         return ;
     }
     QTimer::singleShot (500, this, SLOT (updatePosition ()));
@@ -284,7 +286,8 @@
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
