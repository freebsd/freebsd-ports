--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -36,7 +36,7 @@
 #include "chrome/browser/notifications/notification_platform_bridge_message_center.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #endif
 
@@ -49,7 +49,7 @@ namespace {
 
 #if !defined(OS_CHROMEOS)
 bool NativeNotificationsEnabled(Profile* profile) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (profile) {
     PrefService* prefs = profile->GetPrefs();
     if (!prefs->GetBoolean(prefs::kAllowNativeNotifications))
@@ -131,7 +131,7 @@ NotificationDisplayServiceImpl* NotificationDisplaySer
 // static
 void NotificationDisplayServiceImpl::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kAllowNativeNotifications, true);
 #endif
 }
@@ -148,7 +148,7 @@ NotificationDisplayServiceImpl::NotificationDisplaySer
     AddNotificationHandler(NotificationHandler::Type::WEB_PERSISTENT,
                            std::make_unique<PersistentNotificationHandler>());
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     AddNotificationHandler(
         NotificationHandler::Type::SEND_TAB_TO_SELF,
         std::make_unique<send_tab_to_self::DesktopNotificationHandler>(
