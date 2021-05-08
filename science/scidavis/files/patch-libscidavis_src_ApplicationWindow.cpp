--- libscidavis/src/ApplicationWindow.cpp.orig	2021-05-05 01:51:49 UTC
+++ libscidavis/src/ApplicationWindow.cpp
@@ -4200,7 +4200,7 @@ void ApplicationWindow::readSettings()
     settings.endGroup(); // Colors
 
     settings.beginGroup("/Paths");
-    workingDir = settings.value("/WorkingDir", qApp->applicationDirPath()).toString();
+    workingDir = settings.value("/WorkingDir", QDir::homePath()).toString();
     helpFilePath = settings.value("/HelpFile", "").toString();
 #ifdef PLUGIN_PATH
     QString defaultFitPluginsPath = PLUGIN_PATH;
@@ -8062,6 +8062,10 @@ void ApplicationWindow::showWindowTitleBarMenu()
 void ApplicationWindow::chooseHelpFolder()
 {
 // TODO: move all paths & location handling to anothor class
+#ifdef DOC_PATH
+    const QString locateDefaultHelp = DOC_PATH +
+        QDir::toNativeSeparators("/manual/index.html");
+#else // defined DOC_PATH
 #if defined(Q_OS_WIN)
     const QString locateDefaultHelp =
             qApp->applicationDirPath() + QDir::toNativeSeparators("/manual/index.html");
@@ -8069,6 +8073,8 @@ void ApplicationWindow::chooseHelpFolder()
     const QString locateDefaultHelp =
             QDir::toNativeSeparators("/usr/share/doc/scidavis/manual/index.html");
 #endif
+#endif // defined DOC_PATH
+
     if (QFile(locateDefaultHelp).exists()) {
         helpFilePath = locateDefaultHelp;
     } else {
