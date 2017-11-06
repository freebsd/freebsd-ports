Disable the build of the qml part.

Splitting them out allows us to use websockets in non-gui applications.

--- src/src.pro.orig	2017-06-16 04:39:03 UTC
+++ src/src.pro
@@ -2,4 +2,3 @@ TEMPLATE = subdirs
 CONFIG += ordered
 
 SUBDIRS += websockets
-qtHaveModule(quick): SUBDIRS += imports
