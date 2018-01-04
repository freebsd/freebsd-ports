--- Telegram/SourceFiles/mainwindow.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/mainwindow.cpp
@@ -460,6 +460,7 @@ void MainWindow::ui_hideMediaPreview() {
 void MainWindow::showConnecting(const QString &text, const QString &reconnect) {
 	if (_connecting) {
 		_connecting->set(text, reconnect);
+		_connecting->show();
 	} else {
 		_connecting.create(bodyWidget(), text, reconnect);
 		_connecting->show();
@@ -470,7 +471,7 @@ void MainWindow::showConnecting(const QS
 
 void MainWindow::hideConnecting() {
 	if (_connecting) {
-		_connecting.destroyDelayed();
+		_connecting->hide();
 	}
 }
 
