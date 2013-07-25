Revert the following Gtk+ commit [1], this commit is seems to cause
firefox/thunderbird to crash [2]. Reverting this patch will make ff/tb stop 
crashing while upstream is looking at the exact cause.

[1] https://git.gnome.org/browse/gtk+/commit/?h=gtk-2-24&id=692a0e5906c5da7f85c16c9d6cbb0d3ed8b4a576
[2] https://bugzilla.mozilla.org/show_bug.cgi?id=887587

All information:
http://lists.freebsd.org/pipermail/freebsd-gnome/2013-July/028852.html

--- gdk/gdkwindow.c.orig	2013-07-25 11:01:16.000000000 +0200
+++ gdk/gdkwindow.c	2013-07-25 11:02:24.000000000 +0200
@@ -5463,7 +5463,6 @@
   GdkWindowImplIface *impl_iface;
   gboolean save_region = FALSE;
   GdkRectangle clip_box;
-  int iteration;
 
   /* Ensure the window lives while updating it */
   g_object_ref (window);
@@ -5471,15 +5470,8 @@
   /* If an update got queued during update processing, we can get a
    * window in the update queue that has an empty update_area.
    * just ignore it.
-   *
-   * We run this multiple times if needed because on win32 the
-   * first run can cause new (synchronous) updates from
-   * gdk_window_flush_outstanding_moves(). However, we
-   * limit it to two iterations to avoid any potential loops.
    */
-  iteration = 0;
-  while (private->update_area &&
-	 iteration++ < 2)
+  if (private->update_area)
     {
       GdkRegion *update_area = private->update_area;
       private->update_area = NULL;
