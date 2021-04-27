--- components/feature_engagement/public/event_constants.cc.orig	2021-04-14 18:40:59 UTC
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
@@ -37,7 +37,7 @@ const char kWebUITabStripClosed[] = "webui_tab_strip_c
 const char kWebUITabStripOpened[] = "webui_tab_strip_opened";
 
 const char kDesktopPwaInstalled[] = "desktop_pwa_installed";
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
