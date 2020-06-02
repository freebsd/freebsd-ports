--- ui/gfx/native_widget_types.h.orig	2020-05-15 15:30:28 UTC
+++ ui/gfx/native_widget_types.h
@@ -104,7 +104,7 @@ class ViewAndroid;
 #endif
 class SkBitmap;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern "C" {
 struct _AtkObject;
 typedef struct _AtkObject AtkObject;
@@ -205,7 +205,7 @@ typedef id NativeViewAccessible;
 #elif defined(OS_MACOSX)
 typedef NSFont* NativeFont;
 typedef id NativeViewAccessible;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux doesn't have a native font type.
 typedef AtkObject* NativeViewAccessible;
 #else
