--- components/feature_engagement/public/event_constants.cc.orig	2019-03-11 22:00:56 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -26,9 +26,9 @@ const char kReopenTabConditionsMet[] = "reopen_tab_con
 const char kTabReopened[] = "tab_reopened";
 #endif  // BUILDFLAG(ENABLE_DESKTOP_IN_PRODUCT_HELP)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 
 #if defined(OS_IOS)
 const char kChromeOpened[] = "chrome_opened";
