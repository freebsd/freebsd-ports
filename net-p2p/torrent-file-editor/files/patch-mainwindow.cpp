--- mainwindow.cpp.orig	2026-03-23 00:10:57 UTC
+++ mainwindow.cpp
@@ -576,6 +576,9 @@ void MainWindow::fillCoding()
     for (int mib : QTextCodec::availableMibs()) {
         QTextCodec *codec = QTextCodec::codecForMib(mib);
 
+        // https://github.com/torrent-file-editor/torrent-file-editor/issues/172
+        if (!codec) continue;
+
         QString sortKey = QString::fromUtf8(codec->name().toUpper());
         int rank;
 
