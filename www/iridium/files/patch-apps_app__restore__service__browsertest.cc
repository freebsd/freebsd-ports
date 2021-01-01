--- apps/app_restore_service_browsertest.cc.orig	2020-03-23 15:18:04 UTC
+++ apps/app_restore_service_browsertest.cc
@@ -147,7 +147,7 @@ IN_PROC_BROWSER_TEST_F(PlatformAppBrowserTest, FileAcc
 }
 
 // Flaky: crbug.com/269613
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #define MAYBE_FileAccessIsRestored DISABLED_FileAccessIsRestored
 #else
 #define MAYBE_FileAccessIsRestored FileAccessIsRestored
