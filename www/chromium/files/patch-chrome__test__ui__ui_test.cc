--- ./chrome/test/ui/ui_test.cc.orig	2014-04-30 22:42:44.000000000 +0200
+++ ./chrome/test/ui/ui_test.cc	2014-05-04 14:38:46.000000000 +0200
@@ -68,7 +68,7 @@
     L"NOTE: This test is expected to fail if crash_service.exe is not "
     L"running. Start it manually before running this test (see the build "
     L"output directory).";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
     L"NOTE: This test is expected to fail if breakpad is not built in "
     L"or if chromium is not running headless (try CHROME_HEADLESS=1).";
 #else
