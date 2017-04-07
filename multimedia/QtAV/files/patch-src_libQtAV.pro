--- src/libQtAV.pro.orig	2017-04-06 20:20:44 UTC
+++ src/libQtAV.pro
@@ -18,7 +18,7 @@ staticlib: DEFINES += BUILD_QTAV_STATIC
 static: CONFIG *= static_ffmpeg
 INCLUDEPATH += $$[QT_INSTALL_HEADERS]
 icon.files = $$PWD/$${TARGET}.svg
-icon.path = /usr/share/icons/hicolor/scalable/apps
+icon.path = $$[QT_INSTALL_PREFIX]/share/icons/hicolor/scalable/apps
 !contains(QMAKE_HOST.os, Windows):INSTALLS += icon
 
 #mac: simd.prf will load qt_build_config and the result is soname will prefixed with QT_INSTALL_LIBS and link flag will append soname after QMAKE_LFLAGS_SONAME
