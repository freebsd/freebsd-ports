--- ui/native_theme/native_theme.h.orig	2025-10-02 04:28:32 UTC
+++ ui/native_theme/native_theme.h
@@ -62,7 +62,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) NativeTheme {
   // The part to be painted / sized.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
