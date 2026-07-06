--- components/embedder_support/user_agent_utils.cc.orig	2026-07-01 06:24:19 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -283,7 +283,7 @@ std::string GetUserAgentPlatform() {
   return "";
 #elif BUILDFLAG(IS_MAC)
   return "Macintosh; ";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "X11; ";  // strange, but that's what Firefox uses
 #elif BUILDFLAG(IS_ANDROID)
   return "Linux; ";
@@ -323,7 +323,7 @@ std::string GetUnifiedPlatform() {
   return "Windows NT 10.0; Win64; x64";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "Fuchsia";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "X11; Linux x86_64";
 #elif BUILDFLAG(IS_IOS)
   if (ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET) {
@@ -592,7 +592,7 @@ std::string GetPlatformVersion() {
 
 #if BUILDFLAG(IS_WIN)
   return GetWindowsPlatformVersion();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::string();
 #else
 
@@ -629,6 +629,9 @@ std::string GetPlatformForUAMetadata() {
 #else
   return "Chromium OS";
 #endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
@@ -811,6 +814,16 @@ std::string BuildOSCpuInfoFromOSVersionAndCpuType(cons
                       "Android %s", os_version.c_str()
 #elif BUILDFLAG(IS_FUCHSIA)
                       "Fuchsia"
+#elif BUILDFLAG(IS_BSD)
+#if defined(__x86_64__)
+                      "Linux x86_64; %s %s",
+#elif defined(__aarch64__)
+                      "Linux aarch64; %s %s",
+#else 
+                      "Linux i686; %s %s",
+#endif
+                      unixinfo.sysname,  // e.g. Linux
+                      cpu_type.c_str()   // e.g. i686
 #elif BUILDFLAG(IS_IOS)
                       "CPU %s OS %s like Mac OS X", cpu_type.c_str(),
                       os_version.c_str()
