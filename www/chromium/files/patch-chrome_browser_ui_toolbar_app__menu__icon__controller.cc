--- chrome/browser/ui/toolbar/app_menu_icon_controller.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/toolbar/app_menu_icon_controller.cc
@@ -22,7 +22,7 @@
 #include "ui/gfx/paint_vector_icon.h"
 #include "ui/strings/grit/ui_strings.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/global_features.h"
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
@@ -100,7 +100,7 @@ bool IsUnstableChannel() {
          channel == version_info::Channel::CANARY;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 scheduled_restart::ScheduledRestartManager* GetScheduledRestartManager() {
   return g_browser_process && g_browser_process->GetFeatures()
              ? g_browser_process->GetFeatures()->scheduled_restart_manager()
@@ -128,7 +128,7 @@ AppMenuIconController::AppMenuIconController(UpgradeDe
   global_error_observation_.Observe(
       GlobalErrorServiceFactory::GetForProfile(profile_));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* srm = GetScheduledRestartManager()) {
     schedule_subscription_ =
         srm->AddScheduleChangedCallback(base::BindRepeating(
@@ -150,7 +150,7 @@ void AppMenuIconController::UpdateDelegate() {
 AppMenuIconController::TypeAndSeverity
 AppMenuIconController::GetTypeAndSeverity() const {
 #if !BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Display the badge immediately if a restart is scheduled. By default in
   // production, the first nudge interval (14 days) occurs well after upgrade
   // annoyance is reached, but testing environments or Finch trial configs can
@@ -202,7 +202,7 @@ std::u16string AppMenuIconController::GetIconLabel(Ico
   if (severity == Severity::kNone) {
     return std::u16string();
   } else if (type == IconType::kUpgradeNotification) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kScheduledRestart)) {
       if (auto* srm = GetScheduledRestartManager();
           srm && srm->is_scheduled()) {
@@ -211,7 +211,7 @@ std::u16string AppMenuIconController::GetIconLabel(Ico
     }
 #endif
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     int message_id = IDS_APP_MENU_BUTTON_UPDATE;
     // Select an update text option randomly. Show this text in all browser
     // windows.
@@ -251,7 +251,7 @@ std::u16string AppMenuIconController::GetIconTooltip(I
   if (severity == Severity::kNone) {
     return l10n_util::GetStringUTF16(IDS_APPMENU_TOOLTIP);
   } else if (type == IconType::kUpgradeNotification) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kScheduledRestart)) {
       if (auto* srm = GetScheduledRestartManager();
           srm && srm->is_scheduled()) {
