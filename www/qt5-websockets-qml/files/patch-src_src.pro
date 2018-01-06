We only care about the qml bindings in 'imports'. 
The proper part of websockets is built via www/qt5-websockets.

--- src/src.pro.orig	2017-06-16 04:42:03 UTC
+++ src/src.pro
@@ -2,6 +2,5 @@ TEMPLATE = subdirs
 CONFIG += ordered
 
 qtConfig(textcodec) {
-    SUBDIRS += websockets
     qtHaveModule(quick): SUBDIRS += imports
 }
