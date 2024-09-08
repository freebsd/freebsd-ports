--- chrome/browser/global_desktop_features.cc.orig	2024-08-26 14:40:28 UTC
+++ chrome/browser/global_desktop_features.cc
@@ -45,14 +45,14 @@ void GlobalDesktopFeatures::ReplaceGlobalDesktopFeatur
 }
 
 void GlobalDesktopFeatures::Init() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (user_education::features::IsWhatsNewV2()) {
     whats_new_registry_ = CreateWhatsNewRegistry();
   }
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalDesktopFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
