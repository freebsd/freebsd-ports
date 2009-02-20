--- platform/gtk-x11/xine/xine_impl.c.orig	2009-02-12 06:37:07.000000000 +0900
+++ platform/gtk-x11/xine/xine_impl.c	2009-02-12 18:22:22.000000000 +0900
@@ -251,14 +251,18 @@
     vis.user_data = xine;
   
     /* opening xine output ports */
+    /* Try to use char *driver for video, default to "auto" if NULL */
+    if (!driver)
+            driver = "auto";
+
 #ifdef INCLUDE_XINE_DRIVER_HACK
     miro_using_xv_driver_hack = 0;    /* by default, don't use the hack */
-    xine->videoPort = xine_open_video_driver(xine->xine, "xv",
+    xine->videoPort = xine_open_video_driver(xine->xine, driver,
             XINE_VISUAL_TYPE_X11, (void *)&vis);
     if (!xine->videoPort) {
 #endif
 
-      xine->videoPort = xine_open_video_driver(xine->xine, "auto",
+      xine->videoPort = xine_open_video_driver(xine->xine, driver,
            XINE_VISUAL_TYPE_X11, (void *)&vis);
 
 
