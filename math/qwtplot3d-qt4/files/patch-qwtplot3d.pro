--- ./qwtplot3d.pro.orig	Tue Jun 26 18:34:05 2007
+++ ./qwtplot3d.pro	Tue Jun 26 18:34:57 2007
@@ -1,9 +1,9 @@
 # pro file for building the makefile for qwtplot3d
 #
 
-TARGET            = qwtplot3d
+TARGET            = qwtplot3d-qt4
 TEMPLATE          = lib
-CONFIG           += qt warn_on opengl thread zlib debug
+CONFIG           += qt warn_on opengl thread zlib
 MOC_DIR           = tmp
 OBJECTS_DIR       = tmp
 INCLUDEPATH       = include
@@ -21,7 +21,7 @@
 win32:CONFIG -= zlib
 
 linux-g++:TMAKE_CXXFLAGS += -fno-exceptions
-unix:VERSION = 0.2.6
+unix:VERSION = 0.2.7
 
 # Input
 SOURCES += src/qwt3d_axis.cpp \
