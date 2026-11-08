--- chrome/app/chrome_command_ids.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/app/chrome_command_ids.h
@@ -83,11 +83,11 @@
 #define IDC_TOGGLE_MULTITASK_MENU       34050
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #define IDC_RESTORE_WINDOW              34052
 #endif // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
