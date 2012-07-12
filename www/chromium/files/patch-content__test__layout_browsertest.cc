--- content/test/layout_browsertest.cc.orig	2012-05-30 10:01:22.000000000 +0300
+++ content/test/layout_browsertest.cc	2012-06-05 22:53:35.000000000 +0300
@@ -28,6 +28,8 @@
 static const char kPlatformName[] = "chromium-linux";
 #elif defined(OS_OPENBSD)
 static const char kPlatformName[] = "chromium-openbsd";
+#elif defined(OS_FREEBSD)
+static const char kPlatformName[] = "chromium-freebsd";
 #else
 #error No known OS defined
 #endif
