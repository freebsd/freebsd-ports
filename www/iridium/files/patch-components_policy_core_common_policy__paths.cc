--- components/policy/core/common/policy_paths.cc.orig	2024-06-25 12:08:48 UTC
+++ components/policy/core/common/policy_paths.cc
@@ -13,13 +13,11 @@ namespace policy {
 // policies for the browser.
 // Intentionally not using base::FilePath to minimize dependencies.
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-const char kPolicyPath[] = "/etc/iridium-browser/policies";
-#elif BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
-const char kPolicyPath[] = "/etc/iridium-browser/policies";
+#if BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/iridium/policies";
 #else
-const char kPolicyPath[] = "/etc/iridium-browser/policies";
-#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
+const char kPolicyPath[] = "/etc/iridium/policies";
+#endif
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
 
 }  // namespace policy
