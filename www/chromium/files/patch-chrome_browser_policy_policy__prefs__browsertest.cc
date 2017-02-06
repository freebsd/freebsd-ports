--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -175,6 +175,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
