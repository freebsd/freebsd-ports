--- chrome/browser/browser_process_impl.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -255,7 +255,7 @@
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/fallback_linux_key_provider.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
@@ -267,7 +267,7 @@
 #include "chrome/browser/safe_browsing/safe_browsing_service.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // How often to check if the persistent instance of Chrome needs to restart
 // to install an update.
 static const int kUpdateCheckIntervalHours = 6;
@@ -1181,7 +1181,7 @@ void BrowserProcessImpl::RegisterPrefs(PrefRegistrySim
                                 GoogleUpdateSettings::GetCollectStatsConsent());
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(registry);
 #endif
 }
@@ -1382,7 +1382,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
           local_state())));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   if (cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore) !=
       "basic") {
@@ -1729,7 +1729,7 @@ void BrowserProcessImpl::Unpin() {
 }
 
 // Mac is currently not supported.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
