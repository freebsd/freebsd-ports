--- chrome/browser/ui/webui/webui_js_error/webui_js_error_ui.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/browser/ui/webui/webui_js_error/webui_js_error_ui.cc
@@ -20,7 +20,7 @@
 
 WebUIJsErrorUI::WebUIJsErrorUI(content::WebUI* web_ui)
     : content::WebUIController(web_ui) {
-#if !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   VLOG(3) << std::boolalpha << "chrome://webuijserror loading. "
           << "Experiment state: send javascript errors is "
           << base::FeatureList::IsEnabled(
