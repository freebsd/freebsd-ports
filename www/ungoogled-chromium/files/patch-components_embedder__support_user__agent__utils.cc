--- components/embedder_support/user_agent_utils.cc.orig	2025-04-15 08:30:07 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -439,6 +439,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
