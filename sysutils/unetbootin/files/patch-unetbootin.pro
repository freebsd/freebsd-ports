--- unetbootin.pro.orig	2018-04-28 09:30:55 UTC
+++ unetbootin.pro
@@ -2,18 +2,18 @@ TEMPLATE = app
 TARGET = unetbootin
 DEPENDPATH += .
 INCLUDEPATH += .
-CONFIG += release \
-    static
 
 HEADERS += unetbootin.h
 FORMS += unetbootin.ui
 SOURCES += main.cpp \
     unetbootin.cpp \
+    customdistrolst.cpp \
     distrolst.cpp \
     distrover.cpp \
     distrovercust.cpp
 QT += core \
     gui \
+    widgets \
     network
 ICON = unetbootin.icns
 TRANSLATIONS += unetbootin.ts \
