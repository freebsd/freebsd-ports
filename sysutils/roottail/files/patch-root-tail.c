--- root-tail.c.orig	Fri Nov 19 20:56:03 2004
+++ root-tail.c	Sat Nov 20 18:52:34 2004
@@ -233,17 +233,18 @@
 {
   if (!root)
     {
+			Window unused;
+			Window *windows;
+			unsigned int count;
+
+			Atom type;
+			int format;
+			unsigned long nitems, bytes_after_return;
+			unsigned char *virtual_root_window;
+			
       Atom SWM_VROOT = XInternAtom (display, "__SWM_VROOT", False);
       Atom NAUTILUS_DESKTOP_WINDOW_ID = XInternAtom (display, "NAUTILUS_DESKTOP_WINDOW_ID", False);
       root = RootWindow (display, screen_number);
-
-      Window unused, *windows = 0;
-      unsigned int count;
-
-      Atom type;
-      int format;
-      unsigned long nitems, bytes_after_return;
-      unsigned char *virtual_root_window;
 
       if (XGetWindowProperty (display, root, NAUTILUS_DESKTOP_WINDOW_ID,
                               0, 1, False, XA_WINDOW, &type, &format,
