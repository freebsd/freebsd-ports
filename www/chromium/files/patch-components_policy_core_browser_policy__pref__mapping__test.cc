--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2021-09-24 04:26:04 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -339,6 +339,8 @@ class PolicyTestCase {
     const std::string os("mac");
 #elif defined(OS_WIN)
     const std::string os("win");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
