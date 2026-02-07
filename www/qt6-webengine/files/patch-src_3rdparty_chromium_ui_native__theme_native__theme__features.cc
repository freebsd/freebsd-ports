--- src/3rdparty/chromium/ui/native_theme/native_theme_features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/native_theme/native_theme_features.cc
@@ -73,7 +73,7 @@ bool IsFluentOverlayScrollbarEnabled() {
 
 bool IsFluentOverlayScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFluentOverlayScrollbar);
 #else
   return false;
@@ -82,7 +82,7 @@ bool IsFluentScrollbarEnabled() {
 
 bool IsFluentScrollbarEnabled() {
 // Fluent scrollbars are only used for some OSes due to UI design guidelines.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFluentScrollbar) ||
          IsFluentOverlayScrollbarEnabled();
 #else
