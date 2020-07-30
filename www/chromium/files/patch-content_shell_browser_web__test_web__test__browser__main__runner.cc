--- content/shell/browser/web_test/web_test_browser_main_runner.cc.orig	2020-07-13 09:42:59 UTC
+++ content/shell/browser/web_test/web_test_browser_main_runner.cc
@@ -205,7 +205,7 @@ void WebTestBrowserMainRunner::Initialize() {
   command_line.AppendSwitch(
       switches::kDisableGpuProcessForDX12VulkanInfoCollection);
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   content::WebTestBrowserPlatformInitialize();
 #endif
 
