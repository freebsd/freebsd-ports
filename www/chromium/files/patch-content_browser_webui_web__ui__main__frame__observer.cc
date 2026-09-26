--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2026-09-25 15:26:43 UTC
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -39,7 +39,7 @@ namespace {
 bool IsWebUIJavaScriptErrorReportingSupported() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return false;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(features::kWebUIJSErrorReportingExtended);
