--- chrome/browser/chrome_browser_main.cc.orig	2025-11-06 10:11:34 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -158,7 +158,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "sql/database.h"
 #endif
 
@@ -184,11 +184,11 @@
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_metrics.h"  // nogncheck
 #include "chrome/browser/headless/headless_mode_util.h"     // nogncheck
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
@@ -199,7 +199,7 @@
 #include "ui/gfx/switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/first_run/upgrade_util.h"
 #endif
 
@@ -272,7 +272,7 @@
 #include "chrome/browser/chrome_process_singleton.h"
 #include "chrome/browser/ui/startup/startup_browser_creator.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 #endif  // BUILDFLAG(ENABLE_PROCESS_SINGLETON)
@@ -295,7 +295,7 @@
 
 namespace {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kMediaHistoryDatabaseName[] =
     FILE_PATH_LITERAL("Media History");
 
@@ -444,7 +444,7 @@ void ProcessSingletonNotificationCallbackImpl(
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as a command line switch by another
   // browser process. This also removes the switch after use to prevent any side
   // effects of leaving it in the command line after this point.
@@ -1005,7 +1005,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE) &&                                   \
     (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_ANDROID))
+     BUILDFLAG(IS_ANDROID)) || BUILDFLAG(IS_BSD)
   // Create directory for user-level Native Messaging manifest files. This
   // makes it less likely that the directory will be created by third-party
   // software with incorrect owner or permission. See crbug.com/725513 .
@@ -1049,7 +1049,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
 
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopSessionDurationTracker::Initialize();
   ProfileActivityMetricsRecorder::Initialize();
   TouchUIControllerStatsTracker::Initialize(
@@ -1274,7 +1274,7 @@ void ChromeBrowserMainParts::PostProfileInit(Profile* 
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Delete the media history database if it still exists.
   // TODO(crbug.com/40177301): Remove this.
   base::ThreadPool::PostTask(
@@ -1325,7 +1325,7 @@ void ChromeBrowserMainParts::PostProfileInit(Profile* 
       *UrlLanguageHistogramFactory::GetForBrowserContext(profile));
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::ReportHeadlessActionMetrics();
   }
@@ -1434,7 +1434,7 @@ int ChromeBrowserMainParts::PreMainMessageLoopRunImpl(
   // In headless mode provide alternate SelectFileDialog factory overriding
   // any platform specific SelectFileDialog implementation that may have been
   // set.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::HeadlessSelectFileDialogFactory::SetUp();
   }
@@ -2005,7 +2005,7 @@ bool ChromeBrowserMainParts::ProcessSingletonNotificat
 
   // Drop the request if headless mode is in effect or the request is from
   // a headless Chrome process.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode() ||
       command_line.HasSwitch(switches::kHeadless)) {
     return false;
