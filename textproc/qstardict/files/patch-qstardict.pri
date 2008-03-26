--- ./qstardict.pri.orig	2008-03-22 18:51:46.000000000 +0300
+++ ./qstardict.pri	2008-03-24 01:40:52.000000000 +0300
@@ -37,13 +37,12 @@
 }
 
 unix:DEFINES += HAVE_MMAP
-unix:isEmpty(NO_DBUS):!contains(QT_CONFIG, qdbus): NO_DBUS = 1
 unix:isEmpty(NO_DBUS):CONFIG += qdbus
 unix:isEmpty(NO_DBUS):DEFINES += QSTARDICT_WITH_DBUS
 isEmpty(NO_TRANSLATIONS):DEFINES += QSTARDICT_WITH_TRANSLATIONS
 
 unix {
-    isEmpty(INSTALL_PREFIX):INSTALL_PREFIX=/usr
+    isEmpty(INSTALL_PREFIX):INSTALL_PREFIX=$$(PREFIX)
     isEmpty(BIN_DIR):BIN_DIR=$$INSTALL_PREFIX/bin
     isEmpty(DATA_DIR):DATA_DIR=$$INSTALL_PREFIX/share/qstardict
     isEmpty(NO_TRANSLATIONS):isEmpty(TRANSLATIONS_DIR):TRANSLATIONS_DIR=$$DATA_DIR/translations
