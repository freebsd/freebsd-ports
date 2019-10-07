--- Telegram/SourceFiles/window/main_window.cpp.orig	2019-09-27 17:04:25 UTC
+++ Telegram/SourceFiles/window/main_window.cpp
@@ -571,7 +571,7 @@ bool MainWindow::minimizeToTray() {
 }
 
 void MainWindow::reActivateWindow() {
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	const auto reActivate = [=] {
 		if (const auto w = App::wnd()) {
 			if (auto f = QApplication::focusWidget()) {
@@ -586,7 +586,7 @@ void MainWindow::reActivateWindow() {
 	};
 	crl::on_main(this, reActivate);
 	App::CallDelayed(200, this, reActivate);
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void MainWindow::showRightColumn(object_ptr<TWidget> widget) {
