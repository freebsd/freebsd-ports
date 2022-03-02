--- chrome/browser/browser_process_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -209,7 +209,7 @@
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/error_reporting/chrome_js_error_report_processor.h"  // nogncheck
 #endif
 
@@ -1157,7 +1157,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
 
   ApplyMetricsReportingPolicy();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ChromeJsErrorReportProcessor::Create();
 #endif
 
@@ -1418,7 +1418,7 @@ void BrowserProcessImpl::Unpin() {
 // Mac is currently not supported.
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
