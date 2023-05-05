--- chrome/browser/ui/webui/app_home/app_home_page_handler.cc.orig	2023-05-05 12:12:41 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.cc
@@ -362,7 +362,7 @@ app_home::mojom::AppInfoPtr AppHomePageHandler::Create
 
   bool deprecated_app = false;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   auto* context = extension_system_->extension_service()->GetBrowserContext();
   deprecated_app =
       extensions::IsExtensionUnsupportedDeprecatedApp(context, extension->id());
@@ -425,7 +425,7 @@ void AppHomePageHandler::FillExtensionInfoList(
     }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     auto* context = extension_system_->extension_service()->GetBrowserContext();
     const bool is_deprecated_app =
         extensions::IsExtensionUnsupportedDeprecatedApp(context,
