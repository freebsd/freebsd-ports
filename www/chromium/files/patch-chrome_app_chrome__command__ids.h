--- chrome/app/chrome_command_ids.h.orig	2016-10-06 04:02:10.000000000 +0300
+++ chrome/app/chrome_command_ids.h	2016-10-14 06:38:03.530973000 +0300
@@ -75,7 +75,7 @@
 #define IDC_VISIT_DESKTOP_OF_LRU_USER_2 34049
 #define IDC_VISIT_DESKTOP_OF_LRU_USER_3 34050
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
