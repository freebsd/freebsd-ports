--- ./src/main/main.pro.orig	2014-01-26 16:37:39.000000000 +0330
+++ ./src/main/main.pro	2014-01-26 16:38:07.000000000 +0330
@@ -10,7 +10,7 @@
 TEMPLATE = app
 
 !unix|mac: LIBS += -L../../bin -lQupZilla
-!mac:unix: LIBS += ../../bin/libQupZilla.so
+!mac:unix: LIBS += ../../bin/libQupZilla.so -lexecinfo
 
 include(../defines.pri)
 include(../install.pri)
