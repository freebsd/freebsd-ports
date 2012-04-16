--- ./qwtplot3d.pro.orig	2012-04-16 21:57:23.562053805 +0000
+++ ./qwtplot3d.pro	2012-04-16 21:58:00.311051941 +0000
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
@@ -11,6 +11,7 @@
 DESTDIR      			= lib
 #DESTDIR      			= ../../../lib
 QT += opengl
+unix:LIBS +=	-lGLU
 
 win32:TEMPLATE    = vclib
 win32:CONFIG     += dll exceptions
@@ -21,7 +22,7 @@
 win32:CONFIG -= zlib
 
 linux-g++:TMAKE_CXXFLAGS += -fno-exceptions
-unix:VERSION = 0.2.6
+unix:VERSION = 0.2.7
 
 # Input
 SOURCES += src/qwt3d_axis.cpp \
