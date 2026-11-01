--- chrome/browser/prefs/browser_prefs.cc.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -344,7 +344,7 @@
 #include "chrome/browser/devtools/devtools_window.h"
 #endif  // BUILDFLAG(ENABLE_DEVTOOLS_FRONTEND)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -529,7 +529,7 @@
 #include "chrome/browser/enterprise/platform_auth/platform_auth_policy_observer.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
@@ -558,7 +558,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -875,7 +875,7 @@ inline constexpr char kPendingMetricsReportingLevel[] 
 // Deprecated 07/2026.
 inline constexpr char kObsoleteMetricsReportingLevel[] =
     "user_experience_metrics.reporting_level";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 inline constexpr char kProxyOverrideRulesAffiliation[] =
     "proxy_override_rules_affiliation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -1152,7 +1152,7 @@ void RegisterLocalStatePrefsForMigration(PrefRegistryS
 
   // Deprecated 07/2026.
   registry->RegisterIntegerPref(kObsoleteMetricsReportingLevel, 0);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(kProxyOverrideRulesAffiliation, true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
   registry->RegisterBooleanPref(kMetricsReportingMigrationDone, false);
@@ -1339,7 +1339,7 @@ void RegisterProfilePrefsForMigration(
   registry->RegisterIntegerPref(kMetricsUserReportingLevel, 0);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Deprecated 07/2026.
   registry->RegisterBooleanPref(kProxyOverrideRulesAffiliation, true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -1651,7 +1651,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
   on_device_translation::RegisterLocalStatePrefs(registry);
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scheduled_restart::ScheduledRestartManager::RegisterLocalStatePrefs(registry);
   WhatsNewUI::RegisterLocalStatePrefs(registry);
 #endif
@@ -1817,7 +1817,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
 #endif  // BUILDFLAG(ENABLE_PDF_SAVE_TO_DRIVE)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kChromeForTestingAllowed, true);
 #endif
 
@@ -1946,7 +1946,7 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
   registry->RegisterIntegerPref(prefs::kVoiceTypingSettings, 0);
   registry->RegisterBooleanPref(prefs::kPrefDictationOnboardingCompleted,
                                 false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kVoiceTypingHotkey, "Ctrl+Space");
 #else
   registry->RegisterStringPref(prefs::kVoiceTypingHotkey, "Alt+Space");
@@ -2252,12 +2252,12 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ntp_tiles::EnterpriseShortcutsManagerImpl::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
   enterprise_signin::RegisterProfilePrefs(registry);
 #endif
@@ -2521,7 +2521,7 @@ void MigrateObsoleteLocalStatePrefs(PrefService* local
 
   // Added 07/2026.
   local_state->ClearPref(kObsoleteMetricsReportingLevel);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Added 07/2026.
   local_state->ClearPref(kProxyOverrideRulesAffiliation);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -2733,7 +2733,7 @@ void MigrateObsoleteProfilePrefs(PrefService* profile_
   syncer::ClearAccountKeyedPrefValue(
       profile_prefs, autofill::prefs::kAutofillAiOptInStatus, {});
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Added 07/2026.
   profile_prefs->ClearPref(kProxyOverrideRulesAffiliation);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
