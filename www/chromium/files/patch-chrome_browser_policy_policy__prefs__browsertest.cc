--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -183,6 +183,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
