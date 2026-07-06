--- chrome/browser/browser_process_impl.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -270,7 +270,7 @@ void OnLocalStatePrefsLoaded();
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
@@ -291,7 +291,7 @@ void OnLocalStatePrefsLoaded();
 #include "components/os_crypt/async/common/encryptor.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // How often to check if the persistent instance of Chrome needs to restart
 // to install an update.
 static const int kUpdateCheckIntervalHours = 6;
@@ -1307,7 +1307,7 @@ void BrowserProcessImpl::RegisterPrefs(PrefRegistrySim
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingEnabled, false);
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(registry);
 #endif
 }
@@ -1556,7 +1556,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
           local_state(), /*force_protection_level=*/std::nullopt)));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
@@ -1896,7 +1896,7 @@ void BrowserProcessImpl::Unpin() {
 }
 
 // Mac is currently not supported.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
