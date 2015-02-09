--- ./chrome/browser/policy/policy_prefs_browsertest.cc.orig	2014-04-30 22:41:58.000000000 +0200
+++ ./chrome/browser/policy/policy_prefs_browsertest.cc	2014-05-05 18:09:24.000000000 +0200
@@ -162,6 +162,8 @@
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
