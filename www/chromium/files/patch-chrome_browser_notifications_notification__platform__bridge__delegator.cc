--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2021-01-19 11:25:20 UTC
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -55,7 +55,7 @@ bool NativeNotificationsEnabled(Profile* profile) {
   return true;
 #elif defined(OS_WIN)
   return NotificationPlatformBridgeWin::NativeNotificationEnabled();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
