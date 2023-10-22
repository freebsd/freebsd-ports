--- components/embedder_support/user_agent_utils.cc.orig	2023-10-21 11:51:27 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -432,6 +432,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
