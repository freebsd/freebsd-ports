--- Telegram/SourceFiles/settings/settings_notifications_widget.cpp.orig	2018-02-06 06:27:16 UTC
+++ Telegram/SourceFiles/settings/settings_notifications_widget.cpp
@@ -69,9 +69,9 @@ void NotificationsWidget::createNotifica
 	if (Platform::Notifications::Supported()) {
 #ifdef Q_OS_WIN
 		nativeNotificationsLabel = lang(lng_settings_use_windows);
-#elif defined Q_OS_LINUX64 || defined Q_OS_LINUX32 // Q_OS_WIN
+#elif defined Q_OS_LINUX64 || defined Q_OS_LINUX32 || defined Q_OS_FREEBSD // Q_OS_WIN
 		nativeNotificationsLabel = lang(lng_settings_use_native_notifications);
-#endif // Q_OS_WIN || Q_OS_LINUX64 || Q_OS_LINUX32
+#endif // Q_OS_WIN || Q_OS_LINUX64 || Q_OS_LINUX32 || Q_OS_FREEBSD
 	}
 	if (!nativeNotificationsLabel.isEmpty()) {
 		createChildRow(_nativeNotifications, margin, nativeNotificationsLabel, [this](bool) { onNativeNotifications(); }, Global::NativeNotifications());
