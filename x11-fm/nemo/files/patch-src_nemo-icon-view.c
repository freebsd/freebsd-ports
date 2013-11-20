--- src/nemo-icon-view.orig.c	2013-03-02 09:06:43.664571510 +0100
+++ src/nemo-icon-view.c	2013-03-02 09:06:59.822567644 +0100
@@ -1197,7 +1197,7 @@
 static NemoZoomLevel
 nemo_icon_view_get_default_zoom_level (NemoView *view)
 {
-    g_return_if_fail (NEMO_IS_ICON_VIEW (view));
+    g_return_val_if_fail (NEMO_IS_ICON_VIEW (view), NEMO_ZOOM_LEVEL_STANDARD);
 
     return get_default_zoom_level(NEMO_ICON_VIEW (view));
 }
