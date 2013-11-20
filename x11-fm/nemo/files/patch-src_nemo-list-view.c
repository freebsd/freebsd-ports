--- src/nemo-list-view.orig.c	2013-03-02 09:13:21.519569837 +0100
+++ src/nemo-list-view.c	2013-03-02 09:13:41.166572327 +0100
@@ -2846,7 +2846,7 @@
 static NemoZoomLevel
 nemo_list_view_get_default_zoom_level (NemoView *view)
 {
-    g_return_if_fail (NEMO_IS_LIST_VIEW (view));
+    g_return_val_if_fail (NEMO_IS_LIST_VIEW (view), NEMO_ZOOM_LEVEL_STANDARD);
 
     return get_default_zoom_level();
 }
