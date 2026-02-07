--- libqnapi/src/config/configreader.cpp.orig	2017-05-19 16:50:58 UTC
+++ libqnapi/src/config/configreader.cpp
@@ -175,7 +175,7 @@ const GeneralConfig ConfigReader::resolveP7zipPath(
 
     sysPaths << appExecutableDir;
 
-    QStringList p7zipBinaries = {"7z", "7za"};
+    QStringList p7zipBinaries = {"7z", "7zz"};
 
     foreach (const QString sysPath, sysPaths) {
       foreach (const QString p7zipBinary, p7zipBinaries) {
@@ -192,7 +192,7 @@ const GeneralConfig ConfigReader::resolveP7zipPath(
     }
 
     if (p7zipPath.isEmpty()) {
-      p7zipPath = "7z";
+      p7zipPath = "7zz";
     }
 #endif
 
