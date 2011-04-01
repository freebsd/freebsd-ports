--- gfx/native_widget_types.h.orig	2011-03-20 22:02:04.270736223 +0200
+++ gfx/native_widget_types.h	2011-03-20 22:02:04.441738962 +0200
@@ -97,7 +97,7 @@
 
 #if defined(OS_MACOSX)
 typedef NSImage NativeImageType;
-#elif defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#elif (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOOLKIT_VIEWS)
 typedef GdkPixbuf NativeImageType;
 #else
 typedef SkBitmap NativeImageType;
