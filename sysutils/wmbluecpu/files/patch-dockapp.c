--- dockapp.c	2003-03-23 05:10:15.000000000 +1030
+++ dockapp.c	2009-02-11 12:34:18.897651000 +1030
@@ -238,9 +238,9 @@
 		  32, PropModeReplace, (unsigned char *)&mwmhints, 5);
  }
  XMapWindow(display, mapwindow);
- signal(SIGINT, handle_signal);
- signal(SIGQUIT, handle_signal);
- signal(SIGTERM, handle_signal);
+ //signal(SIGINT, handle_signal);
+ //signal(SIGQUIT, handle_signal);
+ //signal(SIGTERM, handle_signal);
 }
 
 void update_window()
@@ -253,42 +253,55 @@
 {
  XEvent event;
  int winx, winy;
+ fd_set fdset;
+ struct timeval timeout;
 
- XNextEvent(display, &event);
- switch(event.type)
- {
-  case Expose:
-   update_window();
-   break;
-  case ButtonPress:
-   if(opt_window && (event.xbutton.button == 1))
-   {
-    XDefineCursor(display, mapwindow, fleur);
-    moving = 1;
-    oldx = event.xbutton.x;
-    oldy = event.xbutton.y;
-   }
-   break;
-  case MotionNotify:
-   winx = event.xmotion.x_root - oldx;
-   winy = event.xmotion.y_root - oldy;
-   if(winx < 0) winx = 0;
-   if(winy < 0) winy = 0;
-   if(winx > (screenwidth - WINDOW_WIDTH)) winx = screenwidth - WINDOW_WIDTH;
-   if(winy > (screenheight - WINDOW_HEIGHT)) winy = screenheight - WINDOW_HEIGHT;
-   if(moving)
-    XMoveWindow(display, mapwindow, winx, winy);
-   break;
-  case ButtonRelease:
-   if(opt_window)
-   {
-    moving = 0;
-    XUndefineCursor(display, mapwindow);
-   }
-   break;
-  case ClientMessage:
-   if(event.xclient.data.l[0] == wm_delete_window)
-    exitloop = 1;
-   break;
+ FD_ZERO(&fdset);
+ FD_SET(ConnectionNumber(display), &fdset);
+ timeout.tv_usec = opt_timer_miliseconds % 1000;
+ timeout.tv_sec = opt_timer_miliseconds/1000;
+
+ if( select(ConnectionNumber(display)+1, &fdset, NULL, NULL, &timeout) > 0 ){
+     while( XPending( display )){
+	 XNextEvent(display, &event);
+	 switch(event.type)
+	 {
+	     case Expose:
+		 update_window();
+		 break;
+	     case ButtonPress:
+		 if(opt_window && (event.xbutton.button == 1))
+		 {
+		     XDefineCursor(display, mapwindow, fleur);
+		     moving = 1;
+		     oldx = event.xbutton.x;
+		     oldy = event.xbutton.y;
+		 }
+		 break;
+	     case MotionNotify:
+		 winx = event.xmotion.x_root - oldx;
+		 winy = event.xmotion.y_root - oldy;
+		 if(winx < 0) winx = 0;
+		 if(winy < 0) winy = 0;
+		 if(winx > (screenwidth - WINDOW_WIDTH)) winx = screenwidth - WINDOW_WIDTH;
+		 if(winy > (screenheight - WINDOW_HEIGHT)) winy = screenheight - WINDOW_HEIGHT;
+		 if(moving)
+		     XMoveWindow(display, mapwindow, winx, winy);
+		 break;
+	     case ButtonRelease:
+		 if(opt_window)
+		 {
+		     moving = 0;
+		     XUndefineCursor(display, mapwindow);
+		 }
+		 break;
+	     case ClientMessage:
+		 if(event.xclient.data.l[0] == wm_delete_window)
+		     exitloop = 1;
+		 break;
+	 }
+     }
+ } else {
+     handle_timer(SIGALRM);
  }
 }
