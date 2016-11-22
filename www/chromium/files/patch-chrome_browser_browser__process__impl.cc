--- chrome/browser/browser_process_impl.cc.orig	2016-10-06 04:02:11.000000000 +0300
+++ chrome/browser/browser_process_impl.cc	2016-10-16 22:35:35.925144000 +0300
@@ -161,7 +161,7 @@
 #include "chrome/browser/media/webrtc_log_uploader.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/memory/tab_manager.h"
 #endif
 
@@ -765,7 +765,7 @@
 
 memory::TabManager* BrowserProcessImpl::GetTabManager() {
   DCHECK(CalledOnValidThread());
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (!tab_manager_.get())
     tab_manager_.reset(new memory::TabManager());
   return tab_manager_.get();
