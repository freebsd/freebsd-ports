--- chrome/browser/browser_process_impl.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -259,7 +259,7 @@ void OnLocalStatePrefsLoaded();
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
@@ -1196,7 +1196,7 @@ void BrowserProcessImpl::RegisterPrefs(PrefRegistrySim
                                 GoogleUpdateSettings::GetCollectStatsConsent());
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(registry);
 #endif
 }
@@ -1397,7 +1397,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
           local_state())));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
@@ -1418,7 +1418,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
           password_store, l10n_util::GetStringUTF8(IDS_PRODUCT_NAME), nullptr));
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // On other POSIX systems, this is the only key provider.
   providers.emplace_back(
       /*precedence=*/5u, std::make_unique<os_crypt_async::PosixKeyProvider>());
@@ -1746,7 +1746,7 @@ void BrowserProcessImpl::Unpin() {
 }
 
 // Mac is currently not supported.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
