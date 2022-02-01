--- components/feature_engagement/public/event_constants.cc.orig	2021-12-31 00:57:29 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -10,7 +10,7 @@ namespace feature_engagement {
 
 namespace events {
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 const char kNewTabOpened[] = "new_tab_opened";
 const char kSixthTabOpened[] = "sixth_tab_opened";
@@ -47,7 +47,7 @@ const char kFocusHelpBubbleAcceleratorPressed[] =
 const char kFocusHelpBubbleAcceleratorPromoRead[] =
     "focus_help_bubble_accelerator_promo_read";
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_IOS)
