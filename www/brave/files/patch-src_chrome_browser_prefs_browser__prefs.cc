--- src/chrome/browser/prefs/browser_prefs.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/prefs/browser_prefs.cc
@@ -349,7 +349,7 @@
 #include "chrome/browser/devtools/devtools_window.h"
 #endif  // BUILDFLAG(ENABLE_DEVTOOLS_FRONTEND)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -537,11 +537,11 @@
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/pref_names.h"  // nogncheck due to crbug.com/40147906
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
@@ -570,7 +570,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -887,7 +887,7 @@ inline constexpr char kPendingMetricsRep
 // Deprecated 07/2026.
 inline constexpr char kObsoleteMetricsReportingLevel[] =
     "user_experience_metrics.reporting_level";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 inline constexpr char kProxyOverrideRulesAffiliation[] =
     "proxy_override_rules_affiliation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -1094,7 +1094,7 @@ void RegisterLocalStatePrefsForMigration
 
   // Deprecated 07/2026.
   registry->RegisterIntegerPref(kObsoleteMetricsReportingLevel, 0);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(kProxyOverrideRulesAffiliation, true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
   registry->RegisterBooleanPref(kMetricsReportingMigrationDone, false);
@@ -1281,7 +1281,7 @@ void RegisterProfilePrefsForMigration(
   registry->RegisterIntegerPref(kMetricsUserReportingLevel, 0);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Deprecated 07/2026.
   registry->RegisterBooleanPref(kProxyOverrideRulesAffiliation, true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -1547,7 +1547,7 @@ void RegisterLocalState(PrefRegistrySimp
   on_device_translation::RegisterLocalStatePrefs(registry);
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scheduled_restart::ScheduledRestartManager::RegisterLocalStatePrefs(registry);
   WhatsNewUI::RegisterLocalStatePrefs(registry);
 #endif
@@ -1716,7 +1716,7 @@ void RegisterLocalState(PrefRegistrySimp
 #endif  // BUILDFLAG(ENABLE_PDF_SAVE_TO_DRIVE)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kChromeForTestingAllowed, true);
 #endif
 
@@ -1845,7 +1845,7 @@ void RegisterProfilePrefs(user_prefs::Pr
   registry->RegisterIntegerPref(prefs::kVoiceTypingSettings, 0);
   registry->RegisterBooleanPref(prefs::kPrefDictationOnboardingCompleted,
                                 false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kVoiceTypingHotkey, "Ctrl+Space");
 #else
   registry->RegisterStringPref(prefs::kVoiceTypingHotkey, "Alt+Space");
@@ -2156,13 +2156,13 @@ void RegisterProfilePrefs(user_prefs::Pr
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   device_signals::RegisterProfilePrefs(registry);
   ntp_tiles::EnterpriseShortcutsManagerImpl::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
   enterprise_signin::RegisterProfilePrefs(registry);
 #endif
@@ -2429,7 +2429,7 @@ void MigrateObsoleteLocalStatePrefs(Pref
 
   // Added 07/2026.
   local_state->ClearPref(kObsoleteMetricsReportingLevel);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Added 07/2026.
   local_state->ClearPref(kProxyOverrideRulesAffiliation);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -2647,7 +2647,7 @@ void MigrateObsoleteProfilePrefs(PrefSer
   syncer::ClearAccountKeyedPrefValue(
       profile_prefs, autofill::prefs::kAutofillAiOptInStatus, {});
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Added 07/2026.
   profile_prefs->ClearPref(kProxyOverrideRulesAffiliation);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
