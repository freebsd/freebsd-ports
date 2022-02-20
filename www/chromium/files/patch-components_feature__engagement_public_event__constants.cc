--- components/feature_engagement/public/event_constants.cc.orig	2022-02-07 13:39:41 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -11,7 +11,7 @@ namespace feature_engagement {
 namespace events {
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kTabGroupCreated[] = "tab_group_created";
