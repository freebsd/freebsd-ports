--- gui/gui.pro.orig	2017-05-19 20:28:11 UTC
+++ gui/gui.pro
@@ -81,6 +81,7 @@ unix:!macx {
     DESTDIR = ../
     CONFIG += link_pkgconfig
     PKGCONFIG += libmediainfo
+    LIBS += -lmaia
 }
 
 macx {
