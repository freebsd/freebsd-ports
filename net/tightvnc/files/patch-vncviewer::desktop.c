--- vncviewer/desktop.c.orig	Thu Jul 31 00:01:00 2003
+++ vncviewer/desktop.c	Sun Sep 18 19:20:06 2005
@@ -180,8 +180,9 @@
     break;
 
   case FocusIn:
-      XSetInputFocus(dpy, XtWindowOfObject(desktop), RevertToPointerRoot,
-		     CurrentTime);
+      /** XSetInputFocus(dpy, XtWindowOfObject(desktop), RevertToPointerRoot,
+		     CurrentTime); **/
+      XSetInputFocus(dpy, PointerRoot, RevertToPointerRoot, CurrentTime);
     break;
 
   case FocusOut:
