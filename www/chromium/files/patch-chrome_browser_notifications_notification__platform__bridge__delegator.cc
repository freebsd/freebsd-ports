--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2021-09-14 01:51:50 UTC
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -57,7 +57,7 @@ bool SystemNotificationsEnabled(Profile* profile) {
 #elif defined(OS_WIN)
   return NotificationPlatformBridgeWin::SystemNotificationEnabled();
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
@@ -66,7 +66,7 @@ bool SystemNotificationsEnabled(Profile* profile) {
       return false;
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(features::kNativeNotifications) &&
          base::FeatureList::IsEnabled(features::kSystemNotifications);
 #endif  // defined(OS_CHROMEOS) || defined(OS_ANDROID)
