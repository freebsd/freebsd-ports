--- gdk/src/jni/org_gnu_gdk_Display.c.orig	Sat Feb  7 20:32:44 2004
+++ gdk/src/jni/org_gnu_gdk_Display.c	Sat Feb  7 20:39:35 2004
@@ -272,7 +272,8 @@
 JNIEXPORT jint JNICALL Java_org_gnu_gdk_Display_gdk_1display_1get_1window_1at_1pointer
   (JNIEnv *env, jclass cls, jint display, jint x, jint y)
 {
-	return (jint)gdk_display_get_window_at_pointer((GdkDisplay*)display, &(gint)x, &(gint)y);
+    	gint gy = (gint)y, gx = (gint)x;
+	return (jint)gdk_display_get_window_at_pointer((GdkDisplay*)display, &gx, &gy);
 }
 
 /*
