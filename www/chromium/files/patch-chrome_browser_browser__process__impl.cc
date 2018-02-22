--- chrome/browser/browser_process_impl.cc.orig	2017-12-15 02:04:08.000000000 +0100
+++ chrome/browser/browser_process_impl.cc	2017-12-24 00:34:24.918627000 +0100
@@ -170,7 +170,7 @@
 #include "chrome/browser/media/webrtc/webrtc_log_uploader.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/resource_coordinator/tab_manager.h"
 #endif
 
@@ -813,7 +813,7 @@
 
 resource_coordinator::TabManager* BrowserProcessImpl::GetTabManager() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (!tab_manager_)
     tab_manager_ = base::MakeUnique<resource_coordinator::TabManager>();
   return tab_manager_.get();
