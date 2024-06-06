Fix build with Taglib 2.x

Obtained from:
https://github.com/flaviotordini/musique/commit/7277d40defe9cde40f947a81d624195ddf683f44

--- src/mainwindow.cpp.orig	2023-06-24 18:44:28 UTC
+++ src/mainwindow.cpp
@@ -575,6 +575,9 @@ void MainWindow::createToolBar() {
     volumeSlider = new SeekSlider(this);
     volumeSlider->setValue(volumeSlider->maximum());
 
+#include <iostream>
+
+
 #if defined(APP_MAC_SEARCHFIELD) && !defined(APP_MAC_QMACTOOLBAR)
     SearchWrapper *searchWrapper = new SearchWrapper(this);
     toolbarSearch = searchWrapper->getSearchLineEdit();
