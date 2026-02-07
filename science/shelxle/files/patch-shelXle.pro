--- shelXle.pro.orig	2021-01-14 18:57:12 UTC
+++ shelXle.pro
@@ -11,15 +11,15 @@ win32 { 
 !mac{
 unix {
 TARGET = shelxle
-target.path = /usr/bin
+target.path = $$PREFIX/bin
 INSTALLS += target
-data.path = /usr/share/shelxle
+data.path = $$PREFIX/share/shelxle
 data.files = help/*
 INSTALLS += data
-icon.path = /usr/share/pixmaps
+icon.path = $$PREFIX/share/pixmaps
 icon.files = shelxle.png
 INSTALLS += icon
-desktop.path = /usr/share/applications
+desktop.path = $$PREFIX/share/applications
 desktop.files = shelxle.desktop
 INSTALLS += desktop
 }}
