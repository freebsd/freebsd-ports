--- xwin.c.orig	1994-06-05 21:29:24.000000000 +0200
+++ xwin.c	2013-06-13 23:51:03.882547665 +0200
@@ -400,12 +400,14 @@
 		&ascent, &descent, &overall);
 	cheight = overall.ascent + overall.descent;
 	if (height < (cheight + 2))
-		return;
+		return 0;
 
 	/* print label */
 	textx = x + 4;
 	texty = y + height/2.0 + (overall.ascent - overall.descent)/2.0 + 1.5;
 	XDrawString(dpy, win, gc, textx, texty, name, strlen(name));
+
+	return 0;
 }
 
 static Widget popup;
