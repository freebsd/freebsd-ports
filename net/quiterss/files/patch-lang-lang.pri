--- lang/lang.pri.orig	2014-08-03 13:51:31.078727306 +0200
+++ lang/lang.pri	2014-08-03 13:52:13.465776471 +0200
@@ -14,7 +14,7 @@
 
 isEmpty(QMAKE_LRELEASE) {
   Q_OS_WIN:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\lrelease.exe
-  else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
+  else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease-qt4
 }
 
 updateqm.input = TRANSLATIONS
