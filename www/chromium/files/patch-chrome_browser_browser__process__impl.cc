--- chrome/browser/browser_process_impl.cc.orig	2017-09-05 21:05:12.000000000 +0200
+++ chrome/browser/browser_process_impl.cc	2017-09-06 17:46:42.465787000 +0200
@@ -173,7 +173,7 @@
 #include "chrome/browser/media/webrtc/webrtc_log_uploader.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/resource_coordinator/tab_manager.h"
 #endif
 
@@ -796,7 +796,7 @@
 
 resource_coordinator::TabManager* BrowserProcessImpl::GetTabManager() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (!tab_manager_.get())
     tab_manager_.reset(new resource_coordinator::TabManager());
   return tab_manager_.get();
