--- components/device_signals/core/browser/browser_utils.h.orig	2026-10-31 12:09:36 UTC
+++ components/device_signals/core/browser/browser_utils.h
@@ -32,7 +32,7 @@ std::string GetHostName();
 #endif  // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Returns the hostname of the current machine.
 std::vector<std::string> GetSystemDnsServers();
 
@@ -41,7 +41,7 @@ SettingValue GetOSFirewall();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || 
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the path to the ufw configuration file.
 const char** GetUfwConfigPath();
 #endif  // BUILDFLAG(IS_LINUX)
