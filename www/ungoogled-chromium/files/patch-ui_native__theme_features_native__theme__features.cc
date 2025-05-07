--- ui/native_theme/features/native_theme_features.cc.orig	2025-05-06 12:23:00 UTC
+++ ui/native_theme/features/native_theme_features.cc
@@ -59,7 +59,7 @@ namespace ui {
 
 bool IsFluentOverlayScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFluentOverlayScrollbar);
 #else
   return false;
@@ -68,7 +68,7 @@ bool IsFluentOverlayScrollbarEnabled() {
 
 bool IsFluentScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFluentScrollbar) ||
          IsFluentOverlayScrollbarEnabled();
 #else
