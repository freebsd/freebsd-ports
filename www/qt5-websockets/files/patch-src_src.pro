Disable the build of the qml part.

Splitting them out allows us to use websockets in non-gui applications.

--- src/src.pro.orig	2017-06-16 04:39:03 UTC
+++ src/src.pro
@@ -3,5 +3,4 @@ CONFIG += ordered
 
 qtConfig(textcodec) {
     SUBDIRS += websockets
-    qtHaveModule(quick): SUBDIRS += imports
 }
