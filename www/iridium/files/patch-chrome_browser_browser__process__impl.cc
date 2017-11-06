--- chrome/browser/browser_process_impl.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -171,7 +171,7 @@
 #include "chrome/browser/media/webrtc/webrtc_log_uploader.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/memory/tab_manager.h"
 #endif
 
@@ -789,7 +789,7 @@ gcm::GCMDriver* BrowserProcessImpl::gcm_
 
 memory::TabManager* BrowserProcessImpl::GetTabManager() {
   DCHECK(CalledOnValidThread());
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (!tab_manager_.get())
     tab_manager_.reset(new memory::TabManager());
   return tab_manager_.get();
