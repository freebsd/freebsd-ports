--- chrome/browser/browser_process_impl.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -275,7 +275,7 @@ void OnLocalStatePrefsLoaded();
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
@@ -296,7 +296,7 @@ void OnLocalStatePrefsLoaded();
 #include "components/os_crypt/async/common/encryptor.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // How often to check if the persistent instance of Chrome needs to restart
 // to install an update.
 static const int kUpdateCheckIntervalHours = 6;
@@ -1377,7 +1377,7 @@ void BrowserProcessImpl::RegisterPrefs(PrefRegistrySim
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingEnabled, false);
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(registry);
 #endif
 }
@@ -1634,7 +1634,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
           local_state(), /*force_protection_level=*/std::nullopt)));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
@@ -1972,7 +1972,7 @@ void BrowserProcessImpl::Unpin() {
 }
 
 // Mac is currently not supported.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
