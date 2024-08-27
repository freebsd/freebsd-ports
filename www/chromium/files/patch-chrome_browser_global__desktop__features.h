--- chrome/browser/global_desktop_features.h.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/global_desktop_features.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 
 namespace whats_new {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WhatsNewRegistry;
 #endif
 }  // namespace whats_new
@@ -37,7 +37,7 @@ class GlobalDesktopFeatures {
   // Public accessors for features, e.g.
   // FooFeature* foo_feature() { return foo_feature_.get(); }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   whats_new::WhatsNewRegistry* whats_new_registry() {
     return whats_new_registry_.get();
   }
@@ -50,7 +50,7 @@ class GlobalDesktopFeatures {
   // testing. e.g.
   // virtual std::unique_ptr<FooFeature> CreateFooFeature();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual std::unique_ptr<whats_new::WhatsNewRegistry> CreateWhatsNewRegistry();
 #endif
 
@@ -58,7 +58,7 @@ class GlobalDesktopFeatures {
   // Features will each have a controller. e.g.
   // std::unique_ptr<FooFeature> foo_feature_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<whats_new::WhatsNewRegistry> whats_new_registry_;
 #endif
 };
