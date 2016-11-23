--- chrome/browser/browser_process_impl.h.orig	2016-10-06 04:02:11.000000000 +0300
+++ chrome/browser/browser_process_impl.h	2016-10-16 22:37:41.017296000 +0300
@@ -336,7 +336,7 @@
 
   std::unique_ptr<ChromeDeviceClient> device_client_;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   // Any change to this #ifdef must be reflected as well in
   // chrome/browser/memory/tab_manager_browsertest.cc
   std::unique_ptr<memory::TabManager> tab_manager_;
