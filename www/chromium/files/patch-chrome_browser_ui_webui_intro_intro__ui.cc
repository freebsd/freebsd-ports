--- chrome/browser/ui/webui/intro/intro_ui.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/webui/intro/intro_ui.cc
@@ -53,7 +53,7 @@ int GetBackupCardDescriptionId(bool is_first_run_deskt
              : IDS_UNO_FRE_BACKUP_CARD_DESCRIPTION_WITH_PASSWORDS;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsDefaultBrowserDisabledByPolicy() {
   const auto* local_state = g_browser_process->local_state();
   return local_state->IsManagedPreference(
@@ -63,7 +63,7 @@ bool IsDefaultBrowserDisabledByPolicy() {
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 bool ShouldShowDefaultBrowserToggle() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !IsDefaultBrowserDisabledByPolicy() &&
          shell_integration::CanSetAsDefaultBrowser();
 #else
@@ -73,7 +73,7 @@ bool ShouldShowDefaultBrowserToggle() {
 
 bool ShouldShowMetricsOptIn() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   return !metrics::IsMetricsReportingPolicyManaged();
 #else
   return false;
