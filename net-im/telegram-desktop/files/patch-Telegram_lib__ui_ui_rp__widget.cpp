--- Telegram/lib_ui/ui/rp_widget.cpp.orig	2022-04-20 07:41:10 UTC
+++ Telegram/lib_ui/ui/rp_widget.cpp
@@ -11,6 +11,8 @@
 #include <QtGui/QWindow>
 #include <QtGui/QtEvents>
 
+#include <private/qwidget_p.h>
+
 namespace Ui {
 namespace {
 
@@ -207,3 +209,12 @@ auto RpWidgetWrap::eventStreams() const -> EventStream
 }
 
 } // namespace Ui
+
+#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
+
+bool TWidget::setScreen(QScreen *next) {
+	// This method becomes public in Qt6. So anyway reveal it right here.
+	return qt_widget_private(this)->setScreen(next);
+}
+
+#endif  // Qt < 6.0.0
