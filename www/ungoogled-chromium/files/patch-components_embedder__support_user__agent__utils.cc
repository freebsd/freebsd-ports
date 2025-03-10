--- components/embedder_support/user_agent_utils.cc.orig	2025-02-20 09:59:21 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -485,6 +485,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
