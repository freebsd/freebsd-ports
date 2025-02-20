--- components/embedder_support/user_agent_utils.cc.orig	2025-02-19 07:43:18 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -481,6 +481,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
