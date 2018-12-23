--- libscidavis/src/ApplicationWindow.cpp.orig	2018-10-17 03:28:35 UTC
+++ libscidavis/src/ApplicationWindow.cpp
@@ -4253,7 +4253,7 @@ void ApplicationWindow::readSettings()
 	settings.endGroup(); // Colors
 
 	settings.beginGroup("/Paths");
-	workingDir = settings.value("/WorkingDir", qApp->applicationDirPath()).toString();
+	workingDir = settings.value("/WorkingDir", QDir::homePath()).toString();
     helpFilePath = settings.value("/HelpFile", "").toString();
 #ifdef PLUGIN_PATH
 	QString defaultFitPluginsPath = PLUGIN_PATH;
@@ -8209,6 +8209,10 @@ void ApplicationWindow::showWindowTitleB
 void ApplicationWindow::chooseHelpFolder()
 {
 // TODO: move all paths & location handling to anothor class  
+#ifdef DOC_PATH
+	const QString locateDefaultHelp = DOC_PATH +
+	    QDir::toNativeSeparators("/manual/index.html");
+#else // defined DOC_PATH
 #if defined(Q_OS_WIN)
 	const QString locateDefaultHelp = qApp->applicationDirPath() +
         QDir::toNativeSeparators("/manual/index.html");
@@ -8216,6 +8220,8 @@ void ApplicationWindow::chooseHelpFolder
     const QString locateDefaultHelp =
         QDir::toNativeSeparators("/usr/share/doc/scidavis/manual/index.html");
 #endif
+#endif // defined DOC_PATH
+
     if (QFile(locateDefaultHelp).exists())
     {
         helpFilePath = locateDefaultHelp;
