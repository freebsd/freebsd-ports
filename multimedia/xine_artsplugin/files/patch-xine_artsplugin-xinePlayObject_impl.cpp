--- xine_artsplugin/xinePlayObject_impl.cpp.orig
+++ xine_artsplugin/xinePlayObject_impl.cpp
@@ -698,9 +698,12 @@ void xinePlayObject_impl::eventLoop()
 
 	    if (stream != 0)
 	    {
-		xine_gui_send_vo_data( stream,
-				       XINE_GUI_SEND_EXPOSE_EVENT,
-				       &event );
+		// xine_gui_send_vo_data( stream,
+		// 		       XINE_GUI_SEND_EXPOSE_EVENT,
+		// 		       &event );
+		xine_port_send_gui_data( vo_port,
+					 XINE_GUI_SEND_EXPOSE_EVENT,
+					 &event );
 	    }
 	    else
 	    {
@@ -714,7 +717,10 @@ void xinePlayObject_impl::eventLoop()
 
 	    if (stream != 0)
 	    {
-		xine_gui_send_vo_data( stream,
+		// xine_gui_send_vo_data( stream,
+		// 		       XINE_GUI_SEND_COMPLETION_EVENT,
+		// 		       &event );
+		xine_port_send_gui_data( vo_port,
 				       XINE_GUI_SEND_COMPLETION_EVENT,
 				       &event );
 	    }
@@ -748,7 +754,10 @@ void xineVideoPlayObject_impl::x11Window
 	{
 	    resizeNotify();
 
-	    xine_gui_send_vo_data( stream,
+	    // xine_gui_send_vo_data( stream,
+	    //			   XINE_GUI_SEND_DRAWABLE_CHANGED,
+	    //			   (void *)window );
+	    xine_port_send_gui_data( vo_port,
 				   XINE_GUI_SEND_DRAWABLE_CHANGED,
 				   (void *)window );
 	}
