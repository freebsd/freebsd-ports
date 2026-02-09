--- chrome/browser/enterprise/signals/context_info_fetcher.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/enterprise/signals/context_info_fetcher.cc
@@ -184,6 +184,8 @@ std::vector<std::string> ContextInfoFetcher::GetOnSecu
 SettingValue ContextInfoFetcher::GetOSFirewall() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   return device_signals::GetOSFirewall();
+#elif BUILDFLAG(IS_OPENBSD)
+  return SettingValue::ENABLED;
 #elif BUILDFLAG(IS_CHROMEOS)
   return GetChromeosFirewall();
 #else
@@ -203,7 +205,7 @@ ScopedUfwConfigPathForTesting::~ScopedUfwConfigPathFor
 #endif  // BUILDFLAG(IS_LINUX)
 
 std::vector<std::string> ContextInfoFetcher::GetDnsServers() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return device_signals::GetSystemDnsServers();
 #else
   return std::vector<std::string>();
