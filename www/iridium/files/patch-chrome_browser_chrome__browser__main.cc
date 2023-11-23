--- chrome/browser/chrome_browser_main.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -248,11 +248,11 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"
 #endif
 
@@ -287,14 +287,14 @@
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #include "chrome/browser/metrics/desktop_session_duration/touch_mode_stats_tracker.h"
 #include "chrome/browser/profiles/profile_activity_metrics_recorder.h"
 #include "ui/base/pointer/touch_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_metrics.h"  // nogncheck
 #include "chrome/browser/headless/headless_mode_util.h"     // nogncheck
 #include "components/headless/select_file_dialog/headless_select_file_dialog.h"
@@ -1040,7 +1040,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
       browser_creator_->AddFirstRunTabs(master_prefs_->new_tabs);
     }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Create directory for user-level Native Messaging manifest files. This
     // makes it less likely that the directory will be created by third-party
     // software with incorrect owner or permission. See crbug.com/725513 .
@@ -1096,7 +1096,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   metrics::DesktopSessionDurationTracker::Initialize();
   ProfileActivityMetricsRecorder::Initialize();
   TouchModeStatsTracker::Initialize(
@@ -1332,7 +1332,7 @@ void ChromeBrowserMainParts::PostProfileInit(Profile* 
       *UrlLanguageHistogramFactory::GetForBrowserContext(profile));
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::ReportHeadlessActionMetrics();
   }
@@ -1438,7 +1438,7 @@ int ChromeBrowserMainParts::PreMainMessageLoopRunImpl(
   // In headless mode provide alternate SelectFileDialog factory overriding
   // any platform specific SelectFileDialog implementation that may have been
   // set.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::HeadlessSelectFileDialogFactory::SetUp();
   }
@@ -2026,7 +2026,7 @@ bool ChromeBrowserMainParts::ProcessSingletonNotificat
 
   // Drop the request if headless mode is in effect or the request is from
   // a headless Chrome process.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode() ||
       command_line.HasSwitch(switches::kHeadless)) {
     return false;
