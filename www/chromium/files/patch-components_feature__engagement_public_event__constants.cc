--- components/feature_engagement/public/event_constants.cc.orig	2020-09-08 19:14:03 UTC
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
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kTabGroupCreated[] = "tab_group_created";
@@ -45,7 +45,7 @@ const char kIncognitoWindowOpened[] = "incognito_windo
 const char kIncognitoWindowSessionTimeMet[] =
     "incognito_window_session_time_met";
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
