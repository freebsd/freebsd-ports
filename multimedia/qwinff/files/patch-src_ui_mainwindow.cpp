--- src/ui/mainwindow.cpp.orig	2020-10-25 12:05:30 UTC
+++ src/ui/mainwindow.cpp
@@ -48,6 +48,8 @@
 #include <QDebug>
 #include <QUrl>
 
+#define DATA_PATH "%%DATADIR%%"
+
 MainWindow::MainWindow(QWidget *parent, const QStringList& fileList) :
     QMainWindow(parent),
     ui(new Ui::MainWindow),
@@ -673,7 +675,9 @@ int MainWindow::get_poweroff_behavior()
 bool MainWindow::load_presets()
 {
     // The default preset file is located in <datapath>/presets.xml
-    QString default_preset_file = QDir(Paths::dataPath()).absoluteFilePath("presets.xml");
+    //QString default_preset_file = QDir(Paths::dataPath()).absoluteFilePath("presets.xml");
+    QString app_path = QString(DATA_PATH);
+    QString default_preset_file = QDir(app_path).absoluteFilePath("presets.xml");
 
     QString local_preset_file;
     if (!Constants::getBool("Portable")) { // non-portable app
