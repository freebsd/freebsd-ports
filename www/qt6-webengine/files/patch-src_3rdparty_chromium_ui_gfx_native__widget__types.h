--- src/3rdparty/chromium/ui/gfx/native_widget_types.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/gfx/native_widget_types.h
@@ -101,7 +101,7 @@ class SkBitmap;
 #endif
 class SkBitmap;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -214,7 +214,7 @@ using NativeViewAccessible = struct objc_object*;
 #else
 using NativeViewAccessible = struct objc_object*;
 #endif
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native font type.
 using NativeViewAccessible = AtkObject*;
 #else
