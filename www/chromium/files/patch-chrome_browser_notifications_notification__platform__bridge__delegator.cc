--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -57,7 +57,7 @@ bool SystemNotificationsEnabled(Profile* profile) {
 #elif defined(OS_WIN)
   return NotificationPlatformBridgeWin::SystemNotificationEnabled();
 #else
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
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
