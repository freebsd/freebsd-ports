--- ui/gfx/native_widget_types.h.orig	2021-04-14 18:41:39 UTC
+++ ui/gfx/native_widget_types.h
@@ -106,7 +106,7 @@ class SkBitmap;
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 extern "C" {
 struct _AtkObject;
 typedef struct _AtkObject AtkObject;
@@ -209,7 +209,7 @@ typedef NSFont* NativeFont;
 typedef id NativeViewAccessible;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // Linux doesn't have a native font type.
 typedef AtkObject* NativeViewAccessible;
 #else
