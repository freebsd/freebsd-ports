--- ./3rdparty/qwtplot3d/qwtplot3d.pro.orig	2011-01-25 08:07:31.000000000 +0300
+++ ./3rdparty/qwtplot3d/qwtplot3d.pro	2011-03-19 00:18:59.395290422 +0300
@@ -10,7 +10,7 @@
 DEPENDPATH       = include src
 QT              += opengl
 
-CONFIG          += dll
+CONFIG          += static
 win32:CONFIG    += exceptions
 win32:dll:DEFINES    += QT_DLL QWT3D_DLL QWT3D_MAKEDLL
 win32:QMAKE_CXXFLAGS += $$QMAKE_CFLAGS_STL
@@ -39,4 +39,3 @@
 
 # install
 target.path = lib
-INSTALLS += target
