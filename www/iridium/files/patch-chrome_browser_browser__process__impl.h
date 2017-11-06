--- chrome/browser/browser_process_impl.h.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/browser_process_impl.h
@@ -342,7 +342,7 @@ class BrowserProcessImpl : public Browse
 
   std::unique_ptr<ChromeDeviceClient> device_client_;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   // Any change to this #ifdef must be reflected as well in
   // chrome/browser/memory/tab_manager_browsertest.cc
   std::unique_ptr<memory::TabManager> tab_manager_;
