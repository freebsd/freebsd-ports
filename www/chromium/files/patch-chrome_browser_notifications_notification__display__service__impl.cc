--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -29,7 +29,7 @@
 #include "chrome/browser/extensions/api/notifications/extension_notification_handler.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/sharing/sharing_notification_handler.h"
@@ -57,7 +57,7 @@ NotificationDisplayServiceImpl* NotificationDisplaySer
 // static
 void NotificationDisplayServiceImpl::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kAllowNativeNotifications, true);
 #endif
 }
@@ -72,7 +72,7 @@ NotificationDisplayServiceImpl::NotificationDisplaySer
     AddNotificationHandler(NotificationHandler::Type::WEB_PERSISTENT,
                            std::make_unique<PersistentNotificationHandler>());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     AddNotificationHandler(
         NotificationHandler::Type::SEND_TAB_TO_SELF,
