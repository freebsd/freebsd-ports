--- Telegram/SourceFiles/ui/twidget.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/ui/twidget.cpp
@@ -249,9 +249,9 @@ void sendSynteticMouseEvent(QWidget *widget, QEvent::T
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
