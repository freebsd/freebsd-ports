--- chrome/app/chrome_command_ids.h.orig	2023-07-16 15:47:57 UTC
+++ chrome/app/chrome_command_ids.h
@@ -70,12 +70,12 @@
 #define IDC_TOGGLE_MULTITASK_MENU       34050
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define IDC_RESTORE_WINDOW              34052
 #endif
 
