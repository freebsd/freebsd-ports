--- chrome/browser/browser_process_impl.cc.orig	2018-06-13 00:10:04.000000000 +0200
+++ chrome/browser/browser_process_impl.cc	2018-07-14 13:27:02.197056000 +0200
@@ -180,7 +180,7 @@
 #include "chrome/browser/media/webrtc/webrtc_log_uploader.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/resource_coordinator/tab_manager.h"
 #endif
 
@@ -856,7 +856,7 @@
 
 resource_coordinator::TabManager* BrowserProcessImpl::GetTabManager() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (!tab_manager_) {
     tab_manager_ = std::make_unique<resource_coordinator::TabManager>();
     tab_lifecycle_unit_source_ =
