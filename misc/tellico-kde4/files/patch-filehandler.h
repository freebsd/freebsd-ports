--- src/filehandler.h.orig	Tue Feb 17 21:05:58 2004
+++ src/filehandler.h	Tue Feb 17 21:05:06 2004
@@ -131,6 +131,8 @@
   static bool writeDataFile(KSaveFile& file, const QByteArray& data);
 
   static MainWindow* s_mainWindow;
+
+  friend class FileRef;
 };
 
 } // end namespace
