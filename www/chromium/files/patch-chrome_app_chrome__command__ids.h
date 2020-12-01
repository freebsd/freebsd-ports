--- chrome/app/chrome_command_ids.h.orig	2020-11-13 06:36:35 UTC
+++ chrome/app/chrome_command_ids.h
@@ -61,7 +61,7 @@
 #define IDC_ALL_WINDOWS_FRONT           34048
 #define IDC_NAME_WINDOW                 34049
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #define IDC_RESTORE_WINDOW              34052
 #endif
