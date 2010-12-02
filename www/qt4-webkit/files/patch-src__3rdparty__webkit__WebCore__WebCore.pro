--- ./src/3rdparty/webkit/WebCore/WebCore.pro.orig	2010-11-06 04:55:21.000000000 +0300
+++ ./src/3rdparty/webkit/WebCore/WebCore.pro	2010-11-11 12:50:15.632322975 +0300
@@ -82,7 +82,7 @@
     symbian: TARGET =$$TARGET$${QT_LIBINFIX}
 }
 moduleFile=$$PWD/../WebKit/qt/qt_webkit_version.pri
-isEmpty(QT_BUILD_TREE):include($$moduleFile)
+include($$moduleFile)
 VERSION = $${QT_WEBKIT_MAJOR_VERSION}.$${QT_WEBKIT_MINOR_VERSION}.$${QT_WEBKIT_PATCH_VERSION}
 
 unix {
