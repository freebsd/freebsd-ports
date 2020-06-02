--- chrome/app/chrome_command_ids.h.orig	2020-05-13 18:39:36 UTC
+++ chrome/app/chrome_command_ids.h
@@ -60,7 +60,7 @@
 #define IDC_MAXIMIZE_WINDOW             34047
 #define IDC_ALL_WINDOWS_FRONT           34048
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #define IDC_RESTORE_WINDOW              34052
 #endif
