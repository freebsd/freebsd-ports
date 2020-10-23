--- components/feature_engagement/public/event_constants.h.orig	2020-09-08 19:14:03 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -14,15 +14,15 @@ namespace events {
 
 // Desktop and IOS.
 #if defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
 #endif  // defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) ||
-        // defined(OS_LINUX) || defined(OS_CHROMEOS)
+        // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Desktop
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // A new tab was opened when 5 (or more) tabs were already open.
 extern const char kSixthTabOpened[];
@@ -85,7 +85,7 @@ extern const char kIncognitoWindowOpened[];
 extern const char kIncognitoWindowSessionTimeMet[];
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
