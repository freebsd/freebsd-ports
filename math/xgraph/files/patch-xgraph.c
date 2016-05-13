--- xgraph.c.orig	2000-09-10 14:05:47 UTC
+++ xgraph.c
@@ -74,8 +74,6 @@
 #define BTNPAD		1
 #define BTNINTER	3
 
-#define MAX(a,b)	((a) > (b) ? (a) : (b))
-#define MIN(a,b)	((a) < (b) ? (a) : (b))
 #define ABS(x)		((x) < 0 ? -(x) : (x))
 #define ZERO_THRES	1.0E-07
 
@@ -333,6 +331,7 @@ char *argv[];
 	if (!strm) {
 	    (void) fprintf(stderr, "Warning:  cannot open file `%s'\n",
 			   inFileNames[idx]);
+	    errs++;
 	} else {
 	    if ((maxitems = ReadData(strm, inFileNames[idx])) < 0) {
 		errs++;
@@ -403,6 +402,7 @@ char *argv[];
     fg_color = PM_COLOR("Foreground");
     bg_color = PM_COLOR("Background");
     XRecolorCursor(disp, zoomCursor, &fg_color, &bg_color);
+    init_X(win_info->dev_info.user_state);
 
     Num_Windows = 1;
     while (Num_Windows > 0) {
@@ -415,6 +415,12 @@ char *argv[];
 	    continue;
 	}
 	switch (theEvent.type) {
+	case ConfigureNotify:
+		win_info->dev_info.area_w = theEvent.xconfigure.width;
+		win_info->dev_info.area_h = theEvent.xconfigure.height;
+		XClearArea(disp, theEvent.xany.window, 1, 1, win_info->dev_info.area_w, win_info->dev_info.area_h, 0);
+		DrawWindow(win_info);
+		break;
 	case Expose:
 	    if (theEvent.xexpose.count <= 0) {
 		XWindowAttributes win_attr;
@@ -422,7 +428,7 @@ char *argv[];
 		XGetWindowAttributes(disp, theEvent.xany.window, &win_attr);
 		win_info->dev_info.area_w = win_attr.width;
 		win_info->dev_info.area_h = win_attr.height;
-		init_X(win_info->dev_info.user_state);
+		XClearArea(disp, theEvent.xany.window, 1, 1, win_info->dev_info.area_w, win_info->dev_info.area_h, 0);
 		DrawWindow(win_info);
 	    }
 	    break;
@@ -715,7 +721,7 @@ int primary;			/* Is this the primary wi
         if (sizehints.x<0) sizehints.x = 0;
         sizehints.y += 25; 
     }
-#endif
+#else
 
     /* Aspect ratio computation */
     if (asp < 1.0) {
@@ -723,6 +729,7 @@ int primary;			/* Is this the primary wi
     } else {
 	height = ((int) (((double) NORMSIZE) / asp));
     }
+#endif
     height = MAX(MINDIM, height);
     width = MAX(MINDIM, width);
 
@@ -789,7 +796,7 @@ int primary;			/* Is this the primary wi
 
 	new_info->flags = 0;
 	XSelectInput(disp, new_window,
-		     ExposureMask|KeyPressMask|ButtonPressMask);
+		     ExposureMask|KeyPressMask|ButtonPressMask|StructureNotifyMask);
 	if (!theCursor) {
 	    theCursor = XCreateFontCursor(disp, XC_top_left_arrow);
 	    fg_color = PM_COLOR("Foreground");
@@ -1478,6 +1485,8 @@ LineInfo *result;		/* Returned result */
 	    while (*line && (*line != '\n') && (*line != '"')) line++;
 	    if (*line) *line = '\0';
 	} else {
+	    /* treat comma's as white space */
+	    for (first=line; *first; ++first) if (*first == ',') *first = ' ';
 	    first = line;
 	    while (*line && !isspace(*line)) line++;
 	    if (*line) {
