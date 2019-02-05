--- Telegram/SourceFiles/settings/settings_notifications.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/settings/settings_notifications.cpp
@@ -478,11 +478,11 @@ void NotificationsCount::SampleWidget::destroyDelayed(
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
 
 void SetupAdvancedNotifications(not_null<Ui::VerticalLayout*> container) {
