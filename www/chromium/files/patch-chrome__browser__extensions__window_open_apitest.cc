--- chrome/browser/extensions/window_open_apitest.cc.orig	2015-01-14 08:44:00.000000000 +0100
+++ chrome/browser/extensions/window_open_apitest.cc	2015-01-20 19:34:00.351092058 +0100
@@ -263,7 +263,7 @@
   ASSERT_TRUE(RunExtensionTest("window_open/panel")) << message_;
 }
 
-#if defined(USE_ASH_PANELS) || defined(OS_LINUX)
+#if defined(USE_ASH_PANELS) || defined(OS_LINUX) || defined(OS_FREEBSD)
 // On Ash, this currently fails because we're currently opening new panel
 // windows as popup windows instead.
 // We're also failing on Linux-aura due to the panel is not opened in the
