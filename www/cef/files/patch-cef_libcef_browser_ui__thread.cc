--- cef/libcef/browser/ui_thread.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/ui_thread.cc
@@ -11,7 +11,7 @@
 #include "cef/libcef/browser/thread_util.h"
 #include "content/browser/scheduler/browser_task_executor.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ozone_buildflags.h"
 #if BUILDFLAG(SUPPORTS_OZONE_WAYLAND)
 #include "ui/ozone/platform/wayland/ozone_platform_wayland.h"
@@ -70,7 +70,7 @@ bool CefUIThread::WaitUntilThreadStarted
 
 int CefUIThread::InitializeBrowserRunner(
     content::MainFunctionParams main_function_params) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Disable creation of GtkUi (interface to GTK desktop features) and cause
   // ui::GetDefaultLinuxUi() (and related functions) to return nullptr. We
   // can't use GtkUi in combination with multi-threaded-message-loop because
