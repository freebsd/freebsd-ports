--- utils/linux/traydock/libtray.c.orig	2008-12-24 11:30:51.000000000 +0100
+++ utils/linux/traydock/libtray.c	2008-12-24 11:32:00.000000000 +0100
@@ -128,70 +128,25 @@
     //}
 }
 
-static char
-*get_wm_name (void)
-{
-	int screen = DefaultScreen(display);
-	Atom type;
-	int format;
-	unsigned long bytes_returned, n_returned;
-	unsigned char *buffer;
-	
-	Window root = RootWindow(display, screen);
-	Window *child;
-	Atom supwmcheck = XInternAtom(display, "_NET_SUPPORTING_WM_CHECK", False);
-	Atom wmname = XInternAtom(display, "_NET_WM_NAME", False);
-	
-	XGetWindowProperty(display, root, supwmcheck, 0, 8, False, AnyPropertyType, &type, &format, &n_returned,
-			&bytes_returned, (unsigned char **)&child);
-	
-	if (n_returned != 1) return NULL;
-	
-	XGetWindowProperty(display, *child, wmname, 0, 128, False, AnyPropertyType, &type, &format, &n_returned,
-			&bytes_returned, &buffer);
-	
-	if (n_returned == 0) return NULL;
-	
-	XFree(child);
-	return (char *) buffer;
-}
-
 /* Procedure that Docks the icon */
 static void
 DockIcon(ClientData clientData)
 {
 
-	Window root, parent, *children;
-	unsigned int n, ret, atom;
+	Window parent;
+	unsigned int ret, atom;
 	TrayIcon *icon= clientData;
 	char* wm_name;
 
-	Tk_MapWindow(icon->win);
-
-	XQueryTree(display, Tk_WindowId(icon->win), &root, &parent, &children, &n);
-	XFree(children);
+    Tk_MakeWindowExist(icon->win);
 
 	Tk_SetWindowBackgroundPixmap(icon->win, ParentRelative);
-	XSetWindowBackgroundPixmap(display, parent, ParentRelative);
 
 	xembed_set_info(icon->win,XEMBED_MAPPED);
 
-	Tk_UnmapWindow(icon->win);
-
-	if ( (atom = XInternAtom(display, "_NET_SYSTEM_TRAY_OPCODE", True )) == None ) {
-		wm_name = get_wm_name();
-		if (wm_name != NULL && !strcmp(wm_name, "KWin")) {
-			atom = XInternAtom(display, "_KDE_NET_WM_SYSTEM_TRAY_WINDOW_FOR", False);
-			ret = XChangeProperty(display, parent, atom,
-				XA_WINDOW, 32, PropModeReplace, (unsigned char *)&parent, 1);
-			Tk_MapWindow(icon->win);
-		}
-		XFree(wm_name);
-	} else {
-		send_message(display,systemtray, atom,
-				SYSTEM_TRAY_REQUEST_DOCK,Tk_WindowId(icon->win),0,0);
-	}
-
+	atom = XInternAtom(display, "_NET_SYSTEM_TRAY_OPCODE", False );
+	send_message(display,systemtray, atom,
+			SYSTEM_TRAY_REQUEST_DOCK,Tk_WindowId(icon->win),0,0);
 }
 
 /* Draw the icon */
@@ -204,10 +159,32 @@
 	int widthImg, heightImg;
 	Window r;
 	char cmdBuffer[1024];
+	XSizeHints *hints = NULL;
+	long supplied = 0;
 
 	XGetGeometry(display, Tk_WindowId(icon->win), &r, &x, &y, &w, &h, &b, &d);
 	XClearWindow(display, Tk_WindowId(icon->win));
 
+	/*
+	 * Here we get the window hints because in some cases the XGetGeometry
+	 * function returns the wrong width/height. We only check that 
+	 * min_width <= width <= max_width and min_height <= height <= max_height
+	 */
+	hints = XAllocSizeHints();
+	XGetWMNormalHints(display, Tk_WindowId(icon->win), hints, &supplied);
+	if( supplied & PMaxSize ) {
+		w = (hints->max_width < w) ? hints->max_width : w;
+		h = (hints->max_height < h) ? hints->max_height : h;
+	}
+	if( supplied & PMinSize ) {
+		w = (hints->min_width > w) ? hints->min_width : w;
+		h = (hints->min_height > h) ? hints->min_height : h;
+	}
+	if(hints) {
+		XFree(hints);
+		hints = NULL;
+	}
+
 	if (((icon->width != w) || (icon->height != h) || (icon->mustUpdate)) && (icon->cmdCallback[0] != '\0')) {
 		snprintf(cmdBuffer,sizeof(cmdBuffer),"%s %u %u",icon->cmdCallback,w,h);
 		Tcl_EvalEx(globalinterp,cmdBuffer,-1,TCL_EVAL_GLOBAL);
@@ -222,6 +199,8 @@
 	if (heightImg > h)
 		heightImg = h;
 
+	if( !Tk_IsMapped(icon->win) )
+		Tk_MapWindow(icon->win);
 	Tk_RedrawImage(icon->pixmap, 0, 0, widthImg, heightImg, Tk_WindowId(icon->win), (w-widthImg)/2 , (h-heightImg)/2 );
 
 }
@@ -328,6 +307,12 @@
 	XSizeHints *hint;
 	char cmdBuffer[1024];
 
+	/* systemtray was not available in Init */
+	if (systemtray==0) {
+		Tcl_AppendResult (interp, "cannot create a tray icon without a system tray", (char *) NULL);
+		return TCL_ERROR;
+	}
+
 	/* Get memory for trayicon data and zero it*/
 	icon = (TrayIcon *) malloc(sizeof(TrayIcon));
 	memset((void *) icon, 0, (sizeof(TrayIcon)));
@@ -335,18 +320,11 @@
 	
 	mainw=Tk_MainWindow(interp);
 
-	/* systemtray was not available in Init */
-	if (systemtray==0) {
-		Tcl_AppendResult (interp, "cannot create a tray icon without a system tray", (char *) NULL);
-		return TCL_ERROR;
-	}
-
 	/* Get the first argument string (object name) and check it */
 	arg=Tcl_GetStringFromObj(objv[1],(int *) &length);
 	//printf("Arg: %s\n",arg);
-	if (strncmp(arg,".",1)) {
-		Tcl_AppendResult (interp, "bad path name: ",
-			Tcl_GetStringFromObj(objv[1],(int *) &length) , (char *) NULL);
+	if (arg == NULL || length < 1 || strncmp(arg, ".", 1)) {
+		Tcl_AppendResult (interp, "bad path name: ", arg , (char *) NULL);
 		return TCL_ERROR;
 	}
 	
@@ -391,7 +369,7 @@
 				n++;
 				strcpy (icon->tooltip,Tcl_GetStringFromObj(objv[n],(int *) &length));
 			} else if (!strncmp(arg,"-command",length)) {
-				/* Copy tooltip string */
+				/* Copy command string */
 				n++;
 				strcpy (icon->cmdCallback,Tcl_GetStringFromObj(objv[n],(int *) &length));
 			} else {
@@ -408,10 +386,12 @@
 	if (pixmap != NULL) {
 		/* Create the window */
 		icon->win=Tk_CreateWindowFromPath(interp,mainw,
-				Tcl_GetStringFromObj(objv[1],(int *) &length),"");
+				Tcl_GetStringFromObj(objv[1],(int *) &length),NULL);
 
 		DockIcon((ClientData)icon);
 
+		Tk_GeometryRequest( icon->win, 24, 24);
+
 		icon->pixmap=Tk_GetImage(interp,icon->win,pixmap,ImageChangedProc, (ClientData)icon);
 		
 		/* Create callback function for event handling */
@@ -421,9 +401,11 @@
 		
 		/* Set default icon size hint */
 		hint = XAllocSizeHints();
-		hint->flags |=PMinSize;
+		hint->flags |=PMinSize|PMaxSize;
 		hint->min_width=24;
+		hint->max_width=64;
 		hint->min_height=24;
+		hint->max_height=64;
 	
 		XSetWMNormalHints(display,Tk_WindowId(icon->win),hint);
 		XFree(hint);
