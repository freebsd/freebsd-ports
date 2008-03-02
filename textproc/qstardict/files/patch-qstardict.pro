--- ./qstardict.pro.orig	2007-11-11 16:32:55.000000000 +0300
+++ ./qstardict.pro	2007-11-19 01:48:14.000000000 +0300
@@ -5,7 +5,6 @@
 VERSION = 0.08
 DEFINES += QSTARDICT_VERSION=\\\"$$VERSION\\\"
 
-unix:isEmpty(NO_DBUS):!contains(QT_CONFIG, qdbus): NO_DBUS = 1
 
 QT = \
     gui \
