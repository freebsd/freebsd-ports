--- components/embedder_support/user_agent_utils.cc.orig	2025-04-16 18:18:42 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -435,6 +435,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
