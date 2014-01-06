--- ./src/3rdparty/webkit/Source/WebKit/qt/QtWebKit.pro.orig	2011-12-08 06:06:03.000000000 +0100
+++ ./src/3rdparty/webkit/Source/WebKit/qt/QtWebKit.pro	2012-01-08 17:18:52.521346053 +0100
@@ -84,7 +84,7 @@
 }
 
 moduleFile=$$PWD/qt_webkit_version.pri
-isEmpty(QT_BUILD_TREE):include($$moduleFile)
+include($$moduleFile)
 VERSION = $${QT_WEBKIT_MAJOR_VERSION}.$${QT_WEBKIT_MINOR_VERSION}.$${QT_WEBKIT_PATCH_VERSION}
 
 symbian {
