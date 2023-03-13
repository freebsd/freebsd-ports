--- chrome/browser/ui/webui/app_home/app_home_page_handler.cc.orig	2023-03-13 07:33:08 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.cc
@@ -392,7 +392,7 @@ void AppHomePageHandler::FillExtensionInfoList(
     bool is_deprecated_app = false;
     auto* context = extension_service_->GetBrowserContext();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     is_deprecated_app = extensions::IsExtensionUnsupportedDeprecatedApp(
         context, extension->id());
 #endif
