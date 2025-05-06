--- ui/native_theme/native_theme.h.orig	2025-05-05 10:57:53 UTC
+++ ui/native_theme/native_theme.h
@@ -61,7 +61,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) NativeTheme {
   // The part to be painted / sized.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
