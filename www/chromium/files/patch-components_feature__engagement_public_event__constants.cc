--- components/feature_engagement/public/event_constants.cc.orig	2021-07-19 18:45:13 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -10,13 +10,13 @@ namespace feature_engagement {
 
 namespace events {
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const char kNewTabOpened[] = "new_tab_opened";
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kTabGroupCreated[] = "tab_group_created";
@@ -43,7 +43,7 @@ const char kDesktopPwaInstalled[] = "desktop_pwa_insta
 const char kUpdatedConnectionSecurityIndicatorDisplayed[] =
     "updated_connection_security_indicator_displayed";
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
