--- components/embedder_support/user_agent_utils.cc.orig	2025-03-09 21:38:10 UTC
+++ components/embedder_support/user_agent_utils.cc
@@ -455,6 +455,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
