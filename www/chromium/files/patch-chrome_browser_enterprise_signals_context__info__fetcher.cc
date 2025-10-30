--- chrome/browser/enterprise/signals/context_info_fetcher.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/enterprise/signals/context_info_fetcher.cc
@@ -182,6 +182,8 @@ std::vector<std::string> ContextInfoFetcher::GetOnSecu
 SettingValue ContextInfoFetcher::GetOSFirewall() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   return device_signals::GetOSFirewall();
+#elif BUILDFLAG(IS_OPENBSD)
+  return SettingValue::ENABLED;
 #elif BUILDFLAG(IS_CHROMEOS)
   return GetChromeosFirewall();
 #else
@@ -201,7 +203,7 @@ ScopedUfwConfigPathForTesting::~ScopedUfwConfigPathFor
 #endif  // BUILDFLAG(IS_LINUX)
 
 std::vector<std::string> ContextInfoFetcher::GetDnsServers() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return device_signals::GetSystemDnsServers();
 #else
   return std::vector<std::string>();
