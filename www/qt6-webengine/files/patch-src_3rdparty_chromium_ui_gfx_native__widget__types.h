--- src/3rdparty/chromium/ui/gfx/native_widget_types.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gfx/native_widget_types.h
@@ -106,7 +106,7 @@ class SkBitmap;
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 typedef struct _AtkObject AtkObject;
@@ -209,7 +209,7 @@ typedef id NativeViewAccessible;
 typedef id NativeViewAccessible;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native font type.
 typedef AtkObject* NativeViewAccessible;
 #else
