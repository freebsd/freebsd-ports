--- Telegram/SourceFiles/ui/twidget.cpp.orig	2018-12-24 08:16:05 UTC
+++ Telegram/SourceFiles/ui/twidget.cpp
@@ -250,9 +250,9 @@ void sendSynteticMouseEvent(QWidget *wid
 			, button
 			, QGuiApplication::mouseButtons() | button
 			, QGuiApplication::keyboardModifiers()
-#ifndef OS_MAC_OLD
+#if !defined(OS_MAC_OLD) && QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
 			, Qt::MouseEventSynthesizedByApplication
-#endif // OS_MAC_OLD
+#endif
 		);
 		ev.setTimestamp(getms());
 		QGuiApplication::sendEvent(windowHandle, &ev);
