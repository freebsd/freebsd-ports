--- src/conky.cc.orig	2018-01-19 14:12:08 UTC
+++ src/conky.cc
@@ -132,7 +132,7 @@
 #include <microhttpd.h>
 #endif
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ + 0)
 #include <bsd/bsd.h>
 #endif
 
@@ -2073,20 +2073,24 @@ static void main_loop(void)
 	sigaddset(&newmask, SIGUSR1);
 #endif
 
+#ifdef BUILD_X11
 #ifdef BUILD_XSHAPE
-	/* allow only decorated windows to be given mouse input */
-	int major_version, minor_version;
-	if (!XShapeQueryVersion(display, &major_version, &minor_version)) {
-		NORM_ERR("Input shapes are not supported");
-	} else {
-		if (own_window.get(*state) &&
-		    (own_window_type.get(*state) != TYPE_NORMAL ||
-		     (TEST_HINT(own_window_hints.get(*state), HINT_UNDECORATED)))) {
-			XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
-			   NULL, 0, ShapeSet, Unsorted);
+	if (out_to_x.get(*state)) {
+		/* allow only decorated windows to be given mouse input */
+		int major_version, minor_version;
+		if (!XShapeQueryVersion(display, &major_version, &minor_version)) {
+			NORM_ERR("Input shapes are not supported");
+		} else {
+			if (own_window.get(*state) &&
+					(own_window_type.get(*state) != TYPE_NORMAL ||
+					 (TEST_HINT(own_window_hints.get(*state), HINT_UNDECORATED)))) {
+				XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
+						NULL, 0, ShapeSet, Unsorted);
+			}
 		}
 	}
 #endif /* BUILD_XSHAPE */
+#endif /* BUILD_X11 */
 
 	last_update_time = 0.0;
 	next_update_time = get_time() - fmod(get_time(), active_update_interval());
