--- ./src/src.pro.orig	2008-08-05 00:21:54.000000000 +0400
+++ ./src/src.pro	2008-08-09 00:10:20.000000000 +0400
@@ -15,7 +15,7 @@
 
 isEmpty(QMAKE_LRELEASE) {
     win32:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\lrelease.exe
-    else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
+    else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease-qt4
 }
 
 TRANSLATIONS += \
@@ -45,7 +45,7 @@
 PRE_TARGETDEPS += compiler_updateqm_make_all
 
 unix {
-    INSTALLS += target translations desktop iconxpm iconsvg icon16 icon32 icon128 man man-compress
+    INSTALLS += target translations desktop iconxpm iconsvg icon16 icon32 icon128
 
     target.path = $$BINDIR
 
