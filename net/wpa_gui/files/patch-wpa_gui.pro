--- ./wpa_gui.pro.orig	2010-09-07 10:43:39.000000000 -0500
+++ ./wpa_gui.pro	2013-07-05 13:24:16.000000000 -0500
@@ -26,6 +26,7 @@
 } else {
   DEFINES += CONFIG_CTRL_IFACE_UNIX
   SOURCES += ../../src/utils/os_unix.c
+  RESOURCES += icons_png.qrc
 }
 
 INCLUDEPATH	+= . .. ../../src ../../src/utils
