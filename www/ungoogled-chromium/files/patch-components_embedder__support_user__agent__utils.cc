--- components/embedder_support/user_agent_utils.cc.orig	2025-01-25 09:34:31 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -504,6 +504,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
