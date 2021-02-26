--- src/dialog/mainwindow.cpp.orig	2021-02-18 01:06:48 UTC
+++ src/dialog/mainwindow.cpp
@@ -934,7 +934,7 @@ void MainWindow::on_actionAbout_triggered()
     txt += tr("<br>Based on");
     txt += tr("<br>- <a href=\"https://www.infradead.org/openconnect\">OpenConnect</a> ") + QLatin1String(openconnect_get_version());
     txt += tr("<br>- <a href=\"https://www.gnutls.org\">GnuTLS</a> v") + QLatin1String(gnutls_check_version(nullptr));
-    txt += tr("<br>- <a href=\"https://github.com/gabime/spdlog\">spdlog</a> v") + QLatin1String(SPDLOG_VERSION);
+    txt += tr("<br>- <a href=\"https://github.com/gabime/spdlog\">spdlog</a>");
     txt += tr("<br>- <a href=\"https://www.qt.io\">Qt</a> v%1").arg(QT_VERSION_STR);
     txt += tr("<br><br>%1<br>").arg(appCopyright);
     txt += tr("<br><i>%1</i> comes with ABSOLUTELY NO WARRANTY. This is free software, "
