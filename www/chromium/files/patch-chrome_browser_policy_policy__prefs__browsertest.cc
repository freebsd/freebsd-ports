--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -181,6 +181,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
