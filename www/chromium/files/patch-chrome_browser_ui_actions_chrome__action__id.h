--- chrome/browser/ui/actions/chrome_action_id.h.orig	2026-10-22 09:04:01 UTC
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -467,7 +467,7 @@
   E(kActionVisitDesktopOfLruUser3, IDC_VISIT_DESKTOP_OF_LRU_USER_3) \
   E(kActionVisitDesktopOfLruUser4, IDC_VISIT_DESKTOP_OF_LRU_USER_4) \
   E(kActionVisitDesktopOfLruUser5, IDC_VISIT_DESKTOP_OF_LRU_USER_5)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
