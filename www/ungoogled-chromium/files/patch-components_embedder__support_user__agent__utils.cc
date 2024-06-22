--- components/embedder_support/user_agent_utils.cc.orig	2024-06-22 08:49:42 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -449,6 +449,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
