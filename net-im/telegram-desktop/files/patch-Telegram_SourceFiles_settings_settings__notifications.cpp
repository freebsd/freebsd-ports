--- Telegram/SourceFiles/settings/settings_notifications.cpp.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/settings/settings_notifications.cpp
@@ -496,11 +496,11 @@ void NotificationsCount::SampleWidget::destroyDelayed(
 	_deleted = true;
 
 	// Ubuntu has a lag if deleteLater() called immediately.
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	QTimer::singleShot(1000, [this] { delete this; });
-#else // Q_OS_LINUX32 || Q_OS_LINUX64
+#else // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 	deleteLater();
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void SetupAdvancedNotifications(
