--- Telegram/SourceFiles/boxes/notifications_box.cpp.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/boxes/notifications_box.cpp
@@ -84,11 +84,11 @@ private:
 		_deleted = true;
 
 		// Ubuntu has a lag if deleteLater() called immediately.
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 		QTimer::singleShot(1000, [this] { delete this; });
-#else // Q_OS_LINUX32 || Q_OS_LINUX64
+#else // Q_OS_LINUX32 || Q_OS_LINUX64 || defined Q_OS_FREEBSD
 		deleteLater();
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	}
 
 	NotificationsBox *_owner;
