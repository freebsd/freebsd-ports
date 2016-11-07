--- qstardict.pri.orig	2016-11-07 11:15:01 UTC
+++ qstardict.pri
@@ -49,7 +49,6 @@ win32 {
 }
 
 unix:DEFINES += HAVE_MMAP
-unix:isEmpty(NO_DBUS):!contains(QT_CONFIG, dbus): NO_DBUS = 1
 unix:isEmpty(NO_DBUS):CONFIG += qdbus
 unix:isEmpty(NO_DBUS):DEFINES += QSTARDICT_WITH_DBUS
 isEmpty(NO_TRANSLATIONS):DEFINES += QSTARDICT_WITH_TRANSLATIONS
