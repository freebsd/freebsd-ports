--- mng.c.orig	Tue Aug 31 06:03:07 2004
+++ mng.c	Tue Aug 31 06:06:28 2004
@@ -252,6 +252,37 @@
 	/* not implemented yet */
 }
 
+void 
+mng_window_setup(mymng, x, y, width, height)
+	mngstuff	*mymng;
+	int x, y;
+	int width, height;
+{
+	Visual		*get_visual();
+
+	if (!mngdisplay){
+	    if ((mngdisplay = XOpenDisplay(NULL)) == NULL) {
+			fprintf(stderr, "Can't open display\n");
+			exit(-1);
+		}
+		mngscreen = DefaultScreen(mngdisplay);
+		mngvisual = get_visual(mngdisplay, mngscreen, &depth);
+	}
+
+	mymng->window = XCreateSimpleWindow(mngdisplay, 
+		window,
+		0, 0,
+		width, height, 0, 
+		WhitePixel(display, 0), WhitePixel(display, 0));
+
+	XMoveWindow(mngdisplay, mymng->window, x, y);
+	XMapRaised(mngdisplay, mymng->window);
+	XFlush(mngdisplay);
+
+	if (!gcmng)
+		gcmng = XCreateGC(mngdisplay, mymng->window, 0, 0);
+}
+
 void
 mngload(mngfile, x, y, width, height)
 	char *mngfile;
@@ -317,36 +348,6 @@
 	}
 }
 
-void 
-mng_window_setup(mymng, x, y, width, height)
-	mngstuff	*mymng;
-	int x, y;
-	int width, height;
-{
-	Visual		*get_visual();
-
-	if (!mngdisplay){
-	    if ((mngdisplay = XOpenDisplay(NULL)) == NULL) {
-			fprintf(stderr, "Can't open display\n");
-			exit(-1);
-		}
-		mngscreen = DefaultScreen(mngdisplay);
-		mngvisual = get_visual(mngdisplay, mngscreen, &depth);
-	}
-
-	mymng->window = XCreateSimpleWindow(mngdisplay, 
-		window,
-		0, 0,
-		width, height, 0, 
-		WhitePixel(display, 0), WhitePixel(display, 0));
-
-	XMoveWindow(mngdisplay, mymng->window, x, y);
-	XMapRaised(mngdisplay, mymng->window);
-	XFlush(mngdisplay);
-
-	if (!gcmng)
-		gcmng = XCreateGC(mngdisplay, mymng->window, 0, 0);
-}
 
 void
 mngpreload(state, mngfile, width, height)
