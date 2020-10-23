--- content/shell/browser/web_test/web_test_browser_main_runner.cc.orig	2020-09-08 19:14:05 UTC
+++ content/shell/browser/web_test/web_test_browser_main_runner.cc
@@ -208,7 +208,7 @@ void WebTestBrowserMainRunner::Initialize() {
   command_line.AppendSwitch(
       switches::kDisableGpuProcessForDX12VulkanInfoCollection);
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   content::WebTestBrowserPlatformInitialize();
 #endif
 
