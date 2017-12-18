--- Telegram/SourceFiles/ui/twidget.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/ui/twidget.cpp
@@ -191,9 +191,9 @@ void sendSynteticMouseEvent(QWidget *wid
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
