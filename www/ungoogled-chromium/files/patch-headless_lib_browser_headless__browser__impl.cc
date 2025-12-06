--- headless/lib/browser/headless_browser_impl.cc.orig	2025-12-06 13:30:52 UTC
+++ headless/lib/browser/headless_browser_impl.cc
@@ -40,7 +40,7 @@
 #include "components/os_crypt/async/browser/keychain_key_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/command_line.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/password_manager/core/browser/password_manager_switches.h"  // nogncheck
@@ -413,7 +413,7 @@ void HeadlessBrowserImpl::CreateOSCryptAsync() {
   providers.emplace_back(std::make_pair(
       /*precedence=*/10u,
       std::make_unique<os_crypt_async::KeychainKeyProvider>()));
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
