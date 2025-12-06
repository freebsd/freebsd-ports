--- chrome/browser/chrome_browser_main.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -168,7 +168,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "sql/database.h"
 #endif
 
@@ -195,12 +195,12 @@
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_metrics.h"  // nogncheck
 #include "chrome/browser/headless/headless_mode_util.h"     // nogncheck
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
@@ -211,7 +211,7 @@
 #include "ui/gfx/switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/first_run/upgrade_util.h"
 #endif
 
@@ -284,7 +284,7 @@
 #include "chrome/browser/chrome_process_singleton.h"
 #include "chrome/browser/ui/startup/startup_browser_creator.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 #endif  // BUILDFLAG(ENABLE_PROCESS_SINGLETON)
@@ -317,7 +317,7 @@
 #include "chrome/browser/chrome_browser_main_mac.h"
 #elif BUILDFLAG(IS_CHROMEOS)
 #include "chrome/browser/ash/main_parts/chrome_browser_main_parts_ash.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "chrome/browser/chrome_browser_main_android.h"
@@ -325,7 +325,7 @@
 #include "chrome/browser/chrome_browser_main_posix.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/chrome_browser_main_extra_parts_linux.h"
 #elif BUILDFLAG(IS_OZONE)
 #include "chrome/browser/chrome_browser_main_extra_parts_ozone.h"
@@ -334,7 +334,7 @@
 namespace {
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kMediaHistoryDatabaseName[] =
     FILE_PATH_LITERAL("Media History");
 
@@ -483,7 +483,7 @@ void ProcessSingletonNotificationCallbackImpl(
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as a command line switch by another
   // browser process. This also removes the switch after use to prevent any side
   // effects of leaving it in the command line after this point.
@@ -549,7 +549,7 @@ bool ProcessSingletonNotificationCallback(
 
   // Drop the request if headless mode is in effect or the request is from
   // a headless Chrome process.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode() ||
       command_line.HasSwitch(switches::kHeadless)) {
     return false;
@@ -715,7 +715,7 @@ std::unique_ptr<content::BrowserMainParts> ChromeBrows
 #elif BUILDFLAG(IS_CHROMEOS)
   main_parts = std::make_unique<ash::ChromeBrowserMainPartsAsh>(
       is_integration_test, startup_data);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts = std::make_unique<ChromeBrowserMainPartsLinux>(
       is_integration_test, startup_data);
 #elif BUILDFLAG(IS_ANDROID)
@@ -745,7 +745,7 @@ std::unique_ptr<content::BrowserMainParts> ChromeBrows
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -762,7 +762,7 @@ std::unique_ptr<content::BrowserMainParts> ChromeBrows
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsAsh>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif BUILDFLAG(IS_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -1220,7 +1220,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE) &&                                   \
     (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_ANDROID))
+     BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
   // Create directory for user-level Native Messaging manifest files. This
   // makes it less likely that the directory will be created by third-party
   // software with incorrect owner or permission. See crbug.com/725513 .
@@ -1264,7 +1264,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
 
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopSessionDurationTracker::Initialize();
   ProfileActivityMetricsRecorder::Initialize();
   TouchUIControllerStatsTracker::Initialize(
@@ -1478,7 +1478,7 @@ void ChromeBrowserMainParts::PostProfileInit(Profile* 
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Delete the media history database if it still exists.
   // TODO(crbug.com/40177301): Remove this.
   base::ThreadPool::PostTask(
@@ -1529,7 +1529,7 @@ void ChromeBrowserMainParts::PostProfileInit(Profile* 
       *UrlLanguageHistogramFactory::GetForBrowserContext(profile));
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::ReportHeadlessActionMetrics();
   }
@@ -1638,7 +1638,7 @@ int ChromeBrowserMainParts::PreMainMessageLoopRunImpl(
   // In headless mode provide alternate SelectFileDialog factory overriding
   // any platform specific SelectFileDialog implementation that may have been
   // set.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::HeadlessSelectFileDialogFactory::SetUp();
   }
