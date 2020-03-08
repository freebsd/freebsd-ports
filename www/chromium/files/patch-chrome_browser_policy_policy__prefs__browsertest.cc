--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2020-03-03 18:53:01 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -250,6 +250,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
