--- chrome/browser/browser_process_impl.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -257,7 +257,7 @@ void OnLocalStatePrefsLoaded();
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
@@ -1192,7 +1192,7 @@ void BrowserProcessImpl::RegisterPrefs(PrefRegistrySim
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingEnabled, false);
 
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
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
@@ -1721,7 +1721,7 @@ void BrowserProcessImpl::Unpin() {
 }
 
 // Mac is currently not supported.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
