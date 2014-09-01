--- otter.pro.original	2014-08-02 12:12:05.354894688 +0200
+++ otter.pro	2014-08-02 12:12:36.880892354 +0200
@@ -8,7 +8,8 @@
     error("Qt 5.2.0 or newer is required.")
 }
 
-QT += core gui network printsupport script sql webkitwidgets widgets
+QT += core concurrent gui network printsupport script sql webkitwidgets \
+      widgets
 
 win32: QT += winextras
 win32: INCLUDEPATH += .\
