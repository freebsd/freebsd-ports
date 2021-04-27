--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2021-04-14 18:41:00 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -285,6 +285,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
