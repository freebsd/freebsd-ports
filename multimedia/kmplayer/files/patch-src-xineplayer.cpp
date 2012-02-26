--- src/xineplayer.cpp.orig
+++ src/xineplayer.cpp
@@ -528,7 +528,11 @@ void KXinePlayer::play (int repeat) {
     xine_event_create_listener_thread (event_queue, event_listener, NULL);
     if (mrl == "cdda:/") {
         int nr;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
         char ** mrls = xine_get_autoplay_mrls (xine, "CD", &nr);
+#else
+        const char * const * mrls = xine_get_autoplay_mrls (xine, "CD", &nr);
+#endif
         running = 1;
         for (int i = 0; i < nr; i++) {
             QString m (mrls[i]);
@@ -549,7 +553,8 @@ void KXinePlayer::play (int repeat) {
         return;
     }
 
-    xine_gui_send_vo_data(stream, XINE_GUI_SEND_VIDEOWIN_VISIBLE, (void *) 1);
+    // xine_gui_send_vo_data(stream, XINE_GUI_SEND_VIDEOWIN_VISIBLE, (void *) 1);
+    xine_port_send_gui_data(vo_port, XINE_GUI_SEND_VIDEOWIN_VISIBLE, (void *) 1);
 
     running = 1;
     QString mrlsetup = mrl;
@@ -859,10 +864,17 @@ protected:
                             case XK_p: // previous
                                 mutex.lock ();
                                 if (stream) {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
                                     xine_event_t xine_event =  { 
                                         XINE_EVENT_INPUT_PREVIOUS,
                                         stream, 0L, 0, { 0, 0 }
                                     };
+#else
+                                    xine_event_t xine_event =  { 
+                                        stream, 0L, 0,
+                                        XINE_EVENT_INPUT_PREVIOUS, { 0, 0 }
+                                    };
+#endif
                                     xine_event_send (stream, &xine_event);
                                 } 
                                 mutex.unlock ();
@@ -871,10 +883,17 @@ protected:
                             case XK_n: // next
                                 mutex.lock ();
                                 if (stream) {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
                                     xine_event_t xine_event =  { 
                                         XINE_EVENT_INPUT_NEXT,
                                         stream, 0L, 0, { 0, 0 }
                                     };
+#else
+                                    xine_event_t xine_event =  { 
+                                        stream, 0L, 0,
+                                        XINE_EVENT_INPUT_NEXT, { 0, 0 }
+                                    };
+#endif
                                     xine_event_send (stream, &xine_event);
                                 } 
                                 mutex.unlock ();
@@ -883,10 +902,17 @@ protected:
                             case XK_u: // up menu
                                 mutex.lock ();
                                 if (stream) {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
                                     xine_event_t xine_event =  { 
                                         XINE_EVENT_INPUT_MENU1,
                                         stream, 0L, 0, { 0, 0 }
                                     };
+#else
+                                    xine_event_t xine_event =  { 
+                                        stream, 0L, 0,
+                                        XINE_EVENT_INPUT_MENU1, { 0, 0 }
+                                    };
+#endif
                                     xine_event_send (stream, &xine_event);
                                 } 
                                 mutex.unlock ();
@@ -895,10 +921,17 @@ protected:
                             case XK_r: // root menu
                                 mutex.lock ();
                                 if (stream) {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
                                     xine_event_t xine_event =  { 
                                         XINE_EVENT_INPUT_MENU3,
                                         stream, 0L, 0, { 0, 0 }
                                     };
+#else
+                                    xine_event_t xine_event =  { 
+                                        stream, 0L, 0,
+                                        XINE_EVENT_INPUT_MENU3, { 0, 0 }
+                                    };
+#endif
                                     xine_event_send (stream, &xine_event);
                                 } 
                                 mutex.unlock ();
@@ -939,7 +972,8 @@ protected:
                     if(xevent.xexpose.count != 0 || !stream || xevent.xexpose.window != wid)
                         break;
                     mutex.lock ();
-                    xine_gui_send_vo_data(stream, XINE_GUI_SEND_EXPOSE_EVENT, &xevent);
+                    // xine_gui_send_vo_data(stream, XINE_GUI_SEND_EXPOSE_EVENT, &xevent);
+                    xine_port_send_gui_data(vo_port, XINE_GUI_SEND_EXPOSE_EVENT, &xevent);
                     mutex.unlock ();
                     break;
 
@@ -967,17 +1001,25 @@ protected:
                     if (stream) {
                         XMotionEvent *mev = (XMotionEvent *) &xevent;
                         x11_rectangle_t rect = { mev->x, mev->y, 0, 0 };
-                        if (xine_gui_send_vo_data (stream, XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO, (void*) &rect) == -1)
+                        // if (xine_gui_send_vo_data (stream, XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO, (void*) &rect) == -1)
+                        if (xine_port_send_gui_data (vo_port, XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO, (void*) &rect) == -1)
                             break;
                         xine_input_data_t data;
                         data.x = rect.x;
                         data.y = rect.y;
                         data.button = 0;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
                         xine_event_t xine_event =  { 
                                 XINE_EVENT_INPUT_MOUSE_MOVE,
                                 stream, &data, sizeof (xine_input_data_t),
                                 { 0 , 0 }
                         };
+#else
+                        xine_event_t xine_event =  { 
+                                stream, &data, sizeof (xine_input_data_t),
+                                XINE_EVENT_INPUT_MOUSE_MOVE, { 0, 0 }
+                        };
+#endif
                         mutex.lock ();
                         xine_event_send (stream, &xine_event);
                         mutex.unlock ();
@@ -1001,17 +1043,25 @@ protected:
                         fprintf(stderr, "ButtonPress\n");
                         XButtonEvent *bev = (XButtonEvent *) &xevent;
                         x11_rectangle_t rect = { bev->x, bev->y, 0, 0 };
-                        if (xine_gui_send_vo_data (stream, XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO, (void*) &rect) == -1)
+                        // if (xine_gui_send_vo_data (stream, XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO, (void*) &rect) == -1)
+                        if (xine_port_send_gui_data (vo_port, XINE_GUI_SEND_TRANSLATE_GUI_TO_VIDEO, (void*) &rect) == -1)
                             break;
                         xine_input_data_t data;
                         data.x = rect.x;
                         data.y = rect.y;
                         data.button = 1;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
                         xine_event_t xine_event =  { 
                                 XINE_EVENT_INPUT_MOUSE_BUTTON,
                                 stream, &data, sizeof (xine_input_data_t),
                                 { 0, 0 }
                         };
+#else
+                        xine_event_t xine_event =  { 
+                                stream, &data, sizeof (xine_input_data_t),
+                                XINE_EVENT_INPUT_MOUSE_BUTTON, { 0, 0 }
+                        };
+#endif
                         mutex.lock ();
                         xine_event_send (stream, &xine_event);
                         mutex.unlock ();
@@ -1036,7 +1086,8 @@ protected:
             }
 
             if(xevent.type == completion_event && stream)
-                xine_gui_send_vo_data(stream, XINE_GUI_SEND_COMPLETION_EVENT, &xevent);
+                // xine_gui_send_vo_data(stream, XINE_GUI_SEND_COMPLETION_EVENT, &xevent);
+                xine_port_send_gui_data(vo_port, XINE_GUI_SEND_COMPLETION_EVENT, &xevent);
         }
     }
 };
