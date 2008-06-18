--- ./qstardict.pri.orig	2008-06-12 12:55:49.000000000 +0400
+++ ./qstardict.pri	2008-06-12 12:56:16.000000000 +0400
@@ -36,7 +36,6 @@
 windows:LIBS += -lzdll
 
 unix:DEFINES += HAVE_MMAP
-unix:isEmpty(NO_DBUS):!contains(QT_CONFIG, qdbus): NO_DBUS = 1
 unix:isEmpty(NO_DBUS):CONFIG += qdbus
 unix:isEmpty(NO_DBUS):DEFINES += QSTARDICT_WITH_DBUS
 isEmpty(NO_TRANSLATIONS):DEFINES += QSTARDICT_WITH_TRANSLATIONS
