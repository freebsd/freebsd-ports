--- components/feature_engagement/public/event_constants.cc.orig	2021-09-24 04:26:03 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -10,7 +10,7 @@ namespace feature_engagement {
 
 namespace events {
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 const char kNewTabOpened[] = "new_tab_opened";
 const char kSixthTabOpened[] = "sixth_tab_opened";
@@ -39,7 +39,7 @@ const char kDesktopPwaInstalled[] = "desktop_pwa_insta
 const char kUpdatedConnectionSecurityIndicatorDisplayed[] =
     "updated_connection_security_indicator_displayed";
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_IOS)
