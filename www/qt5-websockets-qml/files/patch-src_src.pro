We only care about the qml bindings in 'imports'. 
The proper part of websockets is built via www/qt5-websockets.

--- src/src.pro.orig	2017-06-16 04:42:03 UTC
+++ src/src.pro
@@ -1,5 +1,4 @@
 TEMPLATE = subdirs
 CONFIG += ordered
 
-SUBDIRS += websockets
-qtHaveModule(quick): SUBDIRS += imports
+SUBDIRS += imports
