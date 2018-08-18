--- components/feature_engagement/public/event_constants.cc.orig	2017-12-24 11:50:13.400967000 +0100
+++ components/feature_engagement/public/event_constants.cc	2017-12-24 11:50:56.302146000 +0100
@@ -24,9 +24,9 @@
 
 #endif  // BUILDFLAG(ENABLE_DESKTOP_IN_PRODUCT_HELP)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 
 #if defined(OS_IOS)
 const char kChromeOpened[] = "chrome_opened";
