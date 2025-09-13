--- components/embedder_support/user_agent_utils.cc.orig	2025-09-11 13:19:19 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -317,7 +317,7 @@ std::string GetUserAgentPlatform() {
   return "";
 #elif BUILDFLAG(IS_MAC)
   return "Macintosh; ";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "X11; ";  // strange, but that's what Firefox uses
 #elif BUILDFLAG(IS_ANDROID)
   return "Linux; ";
@@ -333,7 +333,7 @@ std::string GetUserAgentPlatform() {
 }
 
 std::string GetUnifiedPlatform() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   // This constant is only used on Android (desktop) and Linux.
   constexpr char kUnifiedPlatformLinuxX64[] = "X11; Linux x86_64";
 #endif
@@ -353,7 +353,7 @@ std::string GetUnifiedPlatform() {
   return "Windows NT 10.0; Win64; x64";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "Fuchsia";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   return kUnifiedPlatformLinuxX64;
 #elif BUILDFLAG(IS_IOS)
   if (ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET) {
@@ -615,7 +615,7 @@ bool GetMobileBitForUAMetadata() {
 }
 
 std::string GetPlatformVersion() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   // TODO(crbug.com/40245146): Remove this Blink feature
   if (base::FeatureList::IsEnabled(
           blink::features::kReduceUserAgentDataLinuxPlatformVersion)) {
@@ -661,6 +661,9 @@ std::string GetPlatformForUAMetadata() {
 #else
   return "Chromium OS";
 #endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
@@ -873,6 +876,16 @@ std::string BuildOSCpuInfoFromOSVersionAndCpuType(cons
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
