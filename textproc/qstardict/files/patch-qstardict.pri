--- ./qstardict.pri.orig	2009-02-03 21:36:16.000000000 +0300
+++ ./qstardict.pri	2009-02-05 10:24:18.000000000 +0300
@@ -44,7 +44,6 @@
 }
 
 unix:DEFINES += HAVE_MMAP
-unix:isEmpty(NO_DBUS):!contains(QT_CONFIG, dbus): NO_DBUS = 1
 unix:isEmpty(NO_DBUS):CONFIG += qdbus
 unix:isEmpty(NO_DBUS):DEFINES += QSTARDICT_WITH_DBUS
 isEmpty(NO_TRANSLATIONS):DEFINES += QSTARDICT_WITH_TRANSLATIONS
