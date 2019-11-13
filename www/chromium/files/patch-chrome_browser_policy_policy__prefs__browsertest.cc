--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2019-10-21 19:06:22 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -184,6 +184,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
