--- ui/native_theme/features/native_theme_features.cc.orig	2026-03-13 06:02:14 UTC
+++ ui/native_theme/features/native_theme_features.cc
@@ -46,7 +46,7 @@ bool IsFluentOverlayScrollbarEnabled() {
 
 bool IsFluentScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
