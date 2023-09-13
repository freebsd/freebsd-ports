--- components/embedder_support/user_agent_utils.cc.orig	2023-09-13 12:11:42 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -540,6 +540,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
