Q_WS_* is deprecated. Rather than editing the code, just
convince ourselves that on BSD, we would still be using X11.

	https://www.kdab.com/porting-from-qt-4-to-qt-5/

--- qbrew.pro.orig	2008-05-26 02:21:05 UTC
+++ qbrew.pro
@@ -6,6 +6,7 @@
 TARGET = qbrew
 TEMPLATE = app
 CONFIG += qt warn_on
+QT += printsupport widgets xml
 
 MOC_DIR = build
 OBJECTS_DIR = build
@@ -72,6 +73,8 @@ unix:!macx {
         doc.path = /usr/local/share/doc/qbrew
     }
 
+    DEFINES += Q_WS_X11
+
     trans.files = translations/*.qm
     data.files = data/* pics/splash.png
     doc.files = docs/book/*.html docs/primer/*.html README LICENSE
