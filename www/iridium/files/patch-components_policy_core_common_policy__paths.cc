--- components/policy/core/common/policy_paths.cc.orig	2025-12-10 15:04:57 UTC
+++ components/policy/core/common/policy_paths.cc
@@ -17,6 +17,8 @@ namespace policy {
 const char kPolicyPath[] = "/etc/iridium-browser/policies";
 #elif BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 const char kPolicyPath[] = "/etc/iridium-browser/policies";
+#elif BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/iridium-browser/policies";
 #else
 const char kPolicyPath[] = "/etc/iridium-browser/policies";
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
