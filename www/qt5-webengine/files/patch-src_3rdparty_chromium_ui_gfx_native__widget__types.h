--- src/3rdparty/chromium/ui/gfx/native_widget_types.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gfx/native_widget_types.h
@@ -103,7 +103,7 @@ class SkBitmap;
 #endif
 class SkBitmap;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern "C" {
 struct _AtkObject;
 typedef struct _AtkObject AtkObject;
@@ -204,7 +204,7 @@ typedef id NativeViewAccessible;
 #elif defined(OS_MAC)
 typedef NSFont* NativeFont;
 typedef id NativeViewAccessible;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux doesn't have a native font type.
 typedef AtkObject* NativeViewAccessible;
 #else
