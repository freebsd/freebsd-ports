--- multiFileData.cpp.orig	Thu May 21 00:09:57 1998
+++ multiFileData.cpp	Wed Mar 17 17:30:37 2004
@@ -59,8 +59,8 @@
   multiFileList = new QComboBox( FALSE, mainMultiFileOptions, "ComboBox_2" );
   multiFileList->setMinimumSize( 340, 30 );
   multiFileList->setMaximumSize( 32767, 30 );
-  connect( multiFileList, SIGNAL(activated(const char*)), this,
-           SLOT(fileChanged(const char*)) );
+  connect( multiFileList, SIGNAL(activated(const QString&)), this,
+           SLOT(fileChanged(const QString&)) );
   multiFileList->setSizeLimit( 100 );
   multiFileList->setAutoResize( FALSE );
 
@@ -689,7 +689,7 @@
 {
 }
 
-void multiFileData::fileChanged(const char*)
+void multiFileData::fileChanged(const QString&)
 {
 }
 
