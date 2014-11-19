--- Sigram/telegramgui.cpp.orig	2014-11-15 13:31:57.000000000 -0500
+++ Sigram/telegramgui.cpp	2014-11-18 17:49:02.883343868 -0500
@@ -419,9 +419,9 @@
 #ifdef Q_OS_MAC
         *result = QFileInfo(QCoreApplication::applicationDirPath() + "/../Resources/").filePath();
 #else
-        QString res = QCoreApplication::applicationDirPath();
-        if( !QFile::exists(res) )
-            res = QCoreApplication::applicationDirPath() + "../share/sigram";
+        //QString res = QCoreApplication::applicationDirPath();
+        //if( !QFile::exists(res) )
+        QString res = QCoreApplication::applicationDirPath() + "/../share/sigram";
 
         *result = QFileInfo(res).filePath();
 #endif
