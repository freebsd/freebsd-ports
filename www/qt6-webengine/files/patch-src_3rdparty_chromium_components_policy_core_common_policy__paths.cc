--- src/3rdparty/chromium/components/policy/core/common/policy_paths.cc.orig	2023-10-11 18:22:24 UTC
+++ src/3rdparty/chromium/components/policy/core/common/policy_paths.cc
@@ -16,6 +16,8 @@ namespace policy {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) || \
     BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 const char kPolicyPath[] = "/etc/opt/chrome/policies";
+#elif BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/chromium/policies";
 #else
 const char kPolicyPath[] = "/etc/chromium/policies";
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING) || \
