--- content/test/layout_browsertest.cc.orig	2013-02-28 10:14:35.000000000 +0200
+++ content/test/layout_browsertest.cc	2013-03-06 21:29:58.000000000 +0200
@@ -34,6 +34,8 @@
 static const char kPlatformName[] = "chromium-linux";
 #elif defined(OS_OPENBSD)
 static const char kPlatformName[] = "chromium-openbsd";
+#elif defined(OS_FREEBSD)
+static const char kPlatformName[] = "chromium-freebsd";
 #elif defined(OS_ANDROID)
 static const char kPlatformName[] = "chromium-android";
 #else
