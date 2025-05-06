--- components/device_signals/core/browser/browser_utils.h.orig	2025-05-05 10:57:53 UTC
+++ components/device_signals/core/browser/browser_utils.h
@@ -15,7 +15,7 @@ namespace device_signals {
 // Returns the hostname of the current machine.
 std::string GetHostName();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the hostname of the current machine.
 std::vector<std::string> GetSystemDnsServers();
 
@@ -23,7 +23,7 @@ std::vector<std::string> GetSystemDnsServers();
 SettingValue GetOSFirewall();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the path to the ufw configuration file.
 const char** GetUfwConfigPath();
 #endif  // BUILDFLAG(IS_LINUX)
