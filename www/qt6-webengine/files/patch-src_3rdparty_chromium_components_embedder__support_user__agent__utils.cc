--- src/3rdparty/chromium/components/embedder_support/user_agent_utils.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/embedder_support/user_agent_utils.cc
@@ -451,6 +451,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
