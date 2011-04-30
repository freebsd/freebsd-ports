--- ui/gfx/native_widget_types.h.orig	2011-04-16 22:00:39.271073137 +0300
+++ ui/gfx/native_widget_types.h	2011-04-16 22:02:38.712069130 +0300
@@ -97,7 +97,7 @@
 
 #if defined(OS_MACOSX)
 typedef NSImage NativeImageType;
-#elif defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#elif (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOOLKIT_VIEWS)
 typedef GdkPixbuf NativeImageType;
 #else
 typedef SkBitmap NativeImageType;
