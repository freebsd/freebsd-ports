--- src/nemo-view.orig.c	2013-03-02 09:17:03.405569034 +0100
+++ src/nemo-view.c	2013-03-02 09:17:16.902582392 +0100
@@ -680,7 +680,7 @@
 NemoZoomLevel
 nemo_view_get_default_zoom_level (NemoView *view)
 {
-    g_return_if_fail (NEMO_IS_VIEW (view));
+    g_return_val_if_fail (NEMO_IS_VIEW (view), NEMO_ZOOM_LEVEL_STANDARD);
 
     if (!nemo_view_supports_zooming (view)) {
         return -1;
