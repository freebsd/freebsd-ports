--- apps/app_restore_service_browsertest.cc.orig	2020-07-07 21:57:29 UTC
+++ apps/app_restore_service_browsertest.cc
@@ -148,7 +148,7 @@ IN_PROC_BROWSER_TEST_F(PlatformAppBrowserTest, FileAcc
 }
 
 // Flaky: crbug.com/269613
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #define MAYBE_FileAccessIsRestored DISABLED_FileAccessIsRestored
 #else
 #define MAYBE_FileAccessIsRestored FileAccessIsRestored
