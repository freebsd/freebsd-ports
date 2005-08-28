--- widget/src/gtk2/mozdrawingarea.c.orig	Tue Apr 30 12:29:00 2002
+++ widget/src/gtk2/mozdrawingarea.c	Thu Aug 18 22:27:27 2005
@@ -168,7 +168,9 @@
 
     drawingarea = MOZ_DRAWINGAREA(object);
 
+    gdk_window_set_user_data(drawingarea->inner_window, NULL);
     gdk_window_destroy(drawingarea->inner_window);
+    gdk_window_set_user_data(drawingarea->clip_window, NULL);
     gdk_window_destroy(drawingarea->clip_window);
 
     (* parent_class->finalize) (object);
