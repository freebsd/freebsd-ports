--- ui/native_theme/native_theme.h.orig	2024-08-26 14:40:28 UTC
+++ ui/native_theme/native_theme.h
@@ -63,7 +63,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
     kCheckbox,
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
