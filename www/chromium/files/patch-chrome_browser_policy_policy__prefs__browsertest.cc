--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -174,6 +174,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
