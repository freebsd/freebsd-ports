--- gtk/gtkwidget.c.orig	Thu Aug 14 17:51:56 2003
+++ gtk/gtkwidget.c	Thu Aug 14 17:52:52 2003
@@ -3041,6 +3041,9 @@
 static gboolean
 event_window_is_still_viewable (GdkEvent *event)
 {
+  if (GDK_IS_PIXMAP (event->any.window))
+      return event->type == GDK_EXPOSE;
+
   /* Check that we think the event's window is viewable before
    * delivering the event, to prevent suprises. We do this here
    * at the last moment, since the event may have been queued
