--- components/policy/core/common/policy_paths.cc.orig	2023-10-21 11:51:27 UTC
+++ components/policy/core/common/policy_paths.cc
@@ -15,9 +15,11 @@ namespace policy {
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) || \
     BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
-const char kPolicyPath[] = "/etc/iridium-browser/policies";
+const char kPolicyPath[] = "/etc/iridium/policies";
+#elif BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/iridium/policies";
 #else
-const char kPolicyPath[] = "/etc/iridium-browser/policies";
+const char kPolicyPath[] = "/etc/iridium/policies";
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING) || \
         // BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
