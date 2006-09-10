--- qtiplot/src/application.cpp.orig	Wed Sep  6 01:26:14 2006
+++ qtiplot/src/application.cpp	Fri Sep  8 22:21:43 2006
@@ -4240,7 +4240,7 @@
 		workingDir = settings.readEntry("/WorkingDir", qApp->applicationDirPath());
 		templatesDir = settings.readEntry("/TemplatesDir", qApp->applicationDirPath());
 
-		helpFilePath="/usr/share/doc/qtiplot/index.html";
+		helpFilePath=qApp->applicationDirPath()+"/manual/index.html";
 		#ifdef Q_OS_WIN // Windows systems
 			helpFilePath=qApp->applicationDirPath()+"/index.html";
 		#endif
