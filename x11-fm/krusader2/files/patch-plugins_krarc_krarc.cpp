--- plugins/krarc/krarc.cpp.orig	2025-07-16 12:16:19 UTC
+++ plugins/krarc/krarc.cpp
@@ -1568,10 +1568,10 @@ KIO::WorkerResult kio_krarcProtocol::initArcParameters
 
     if (arcType == "zip") {
         noencoding = true;
-        cmd = fullPathName("unzip");
-        listCmd << fullPathName("unzip") << "-ZTs-z-t-h";
-        getCmd << fullPathName("unzip") << "-p";
-        copyCmd << fullPathName("unzip") << "-jo";
+        cmd = QString("%%LOCALBASE%%/bin/unzip");
+        listCmd << cmd << "-ZTs-z-t-h";
+        getCmd << cmd << "-p";
+        copyCmd << cmd << "-jo";
 
         if (QStandardPaths::findExecutable(QStringLiteral("zip")).isEmpty()) {
             delCmd = QStringList();
