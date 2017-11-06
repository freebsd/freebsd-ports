--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -180,6 +180,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
