
$FreeBSD$

--- c_src/gtk_drv.c.orig	Tue Nov  4 13:41:13 2003
+++ c_src/gtk_drv.c	Tue Nov  4 13:42:12 2003
@@ -2203,7 +2203,7 @@
 	return gdrv_encode_ulong(mpp, 0);
     }
 
-    if (type == GDK_TYPE_EVENT) {
+    if (gtk_type_is_a(type, GDK_TYPE_EVENT)) {
 	return encode_gdk_event(mpp, (GdkEvent*) ptr);
     }
     else if ((type == GDK_TYPE_WINDOW)||(type == GDK_TYPE_PIXMAP) ||
