--- ui/native_theme/native_theme.h.orig	2026-01-14 08:33:23 UTC
+++ ui/native_theme/native_theme.h
@@ -64,7 +64,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) NativeTheme {
   // A part being sized or painted.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
