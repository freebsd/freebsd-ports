--- ui/native_theme/native_theme.h.orig	2025-10-30 15:44:36 UTC
+++ ui/native_theme/native_theme.h
@@ -61,7 +61,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) NativeTheme {
   // A part being sized or painted.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
