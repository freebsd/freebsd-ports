--- chrome/browser/ui/actions/chrome_action_id.h.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -504,7 +504,7 @@
 #if BUILDFLAG(IS_CHROMEOS)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kToggleMultitaskMenu, IDC_TOGGLE_MULTITASK_MENU)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
