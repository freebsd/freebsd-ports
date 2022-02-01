--- components/feature_engagement/public/event_constants.h.orig	2021-12-31 00:57:29 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -12,7 +12,7 @@ namespace feature_engagement {
 namespace events {
 
 // Desktop
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
@@ -75,7 +75,7 @@ extern const char kFocusHelpBubbleAcceleratorPressed[]
 // the user.
 extern const char kFocusHelpBubbleAcceleratorPromoRead[];
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_IOS)
