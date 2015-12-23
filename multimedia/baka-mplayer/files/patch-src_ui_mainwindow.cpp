Explicitly use <cmath> to unbreak build with libc++

src/ui/mainwindow.cpp:996:53: error: use of undeclared identifier 'ceil'
        playlistRect.setLeft(playlistRect.right() - ceil(playlistRect.width()/7.0))

https://github.com/u8sand/Baka-MPlayer/pull/169

--- src/ui/mainwindow.cpp.orig	2015-12-01 16:03:48 UTC
+++ src/ui/mainwindow.cpp
@@ -1,6 +1,7 @@
 #include "mainwindow.h"
 #include "ui_mainwindow.h"
 
+#include <cmath>
 #include <QLibraryInfo>
 #include <QMimeData>
 #include <QDesktopWidget>
@@ -993,7 +994,7 @@ void MainWindow::mouseMoveEvent(QMouseEv
         ui->seekBar->setVisible(showPlayback || ui->outputTextEdit->isVisible());
 
         QRect playlistRect = geometry();
-        playlistRect.setLeft(playlistRect.right() - ceil(playlistRect.width()/7.0));
+        playlistRect.setLeft(playlistRect.right() - std::ceil(playlistRect.width()/7.0));
         bool showPlaylist = playlistRect.contains(event->globalPos());
         ShowPlaylist(showPlaylist);
 
