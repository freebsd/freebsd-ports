--- ./chrome/browser/policy/policy_prefs_browsertest.cc.orig	2014-08-12 21:01:40.000000000 +0200
+++ ./chrome/browser/policy/policy_prefs_browsertest.cc	2014-08-13 09:56:56.000000000 +0200
@@ -169,6 +169,8 @@
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
