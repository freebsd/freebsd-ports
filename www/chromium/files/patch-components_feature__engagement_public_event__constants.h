--- components/feature_engagement/public/event_constants.h.orig	2022-02-07 13:39:41 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -13,7 +13,7 @@ namespace events {
 
 // Desktop
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
