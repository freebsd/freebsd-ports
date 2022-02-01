--- ui/native_theme/native_theme.h.orig	2021-12-31 00:58:32 UTC
+++ ui/native_theme/native_theme.h
@@ -57,7 +57,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
     kCheckbox,
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
