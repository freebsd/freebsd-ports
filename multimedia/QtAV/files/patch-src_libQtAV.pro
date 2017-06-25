--- src/libQtAV.pro.orig	2017-06-21 01:47:15 UTC
+++ src/libQtAV.pro
@@ -614,7 +614,7 @@ mac {
 
 unix:!mac:!cross_compile {
 icon.files = $$PWD/$${TARGET}.svg
-icon.path = /usr/share/icons/hicolor/scalable/apps
+icon.path = $$[QT_INSTALL_PREFIX]/share/icons/hicolor/scalable/apps
 INSTALLS += icon
 #debian
 DEB_INSTALL_LIST = .$$[QT_INSTALL_LIBS]/libQt*AV.so.*
