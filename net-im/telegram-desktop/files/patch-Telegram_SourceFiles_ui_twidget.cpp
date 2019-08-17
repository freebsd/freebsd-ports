--- Telegram/SourceFiles/ui/twidget.cpp.orig	2019-07-07 13:34:35 UTC
+++ Telegram/SourceFiles/ui/twidget.cpp
@@ -270,9 +270,9 @@ void sendSynteticMouseEvent(QWidget *widget, QEvent::T
 			, button
 			, QGuiApplication::mouseButtons() | button
 			, QGuiApplication::keyboardModifiers()
-#ifndef OS_MAC_OLD
+#if !defined(OS_MAC_OLD) && QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
 			, Qt::MouseEventSynthesizedByApplication
-#endif // OS_MAC_OLD
+#endif
 		);
 		ev.setTimestamp(crl::now());
 		QGuiApplication::sendEvent(windowHandle, &ev);
