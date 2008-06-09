Index: gdk/x11/gdkwindow-x11.c
===================================================================
--- gdk/x11/gdkwindow-x11.c	(revision 20280)
+++ gdk/x11/gdkwindow-x11.c	(working copy)
@@ -3412,6 +3412,7 @@
   Window xwindow;
   Window xparent;
   Window root;
+  Window child;
   Window *children;
   guchar *data;
   Window *vroots;
@@ -3470,13 +3471,15 @@
       if ((type_return == XA_CARDINAL) && (format_return == 32) &&
 	  (nitems_return == 4) && (data))
         {
-	  guint32 *ldata = (guint32 *) data;
+	  gulong *ldata = (gulong *) data;
 	  got_frame_extents = TRUE;
 
 	  /* try to get the real client window geometry */
 	  if (XGetGeometry (GDK_DISPLAY_XDISPLAY (display), xwindow,
-			    &root, &wx, &wy, &ww, &wh, &wb, &wd))
-	    {
+			    &root, &wx, &wy, &ww, &wh, &wb, &wd) &&
+              XTranslateCoordinates (GDK_DISPLAY_XDISPLAY (display),
+	  			     xwindow, root, 0, 0, &wx, &wy, &child))
+            {
 	      rect->x = wx;
 	      rect->y = wy;
 	      rect->width = ww;
