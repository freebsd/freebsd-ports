--- components/feature_engagement/public/event_constants.cc.orig	2019-10-21 19:06:29 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -12,12 +12,12 @@ namespace feature_engagement {
 namespace events {
 
 #if defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 #endif  // defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) ||
-        // defined(OS_LINUX) || defined(OS_CHROMEOS)
+        // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const char kReopenTabConditionsMet[] = "reopen_tab_conditions_met";
 const char kTabReopened[] = "tab_reopened";
@@ -39,7 +39,7 @@ const char kIncognitoWindowOpened[] = "incognito_windo
 const char kIncognitoWindowSessionTimeMet[] =
     "incognito_window_session_time_met";
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
