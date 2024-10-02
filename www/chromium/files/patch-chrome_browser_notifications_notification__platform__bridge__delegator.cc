--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -56,7 +56,7 @@ bool SystemNotificationsEnabled(Profile* profile) {
 #elif BUILDFLAG(IS_WIN)
   return NotificationPlatformBridgeWin::SystemNotificationEnabled();
 #else
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
