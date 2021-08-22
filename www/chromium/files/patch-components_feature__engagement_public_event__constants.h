--- components/feature_engagement/public/event_constants.h.orig	2021-07-19 18:45:13 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -12,16 +12,16 @@ namespace feature_engagement {
 namespace events {
 
 // Desktop and IOS.
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 // Desktop
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // A new tab was opened when 5 (or more) tabs were already open.
 extern const char kSixthTabOpened[];
@@ -69,7 +69,7 @@ extern const char kDesktopPwaInstalled[];
 // Omnibox displayed the updated connection security indicator.
 extern const char kUpdatedConnectionSecurityIndicatorDisplayed[];
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
