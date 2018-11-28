--- qwtplot3d.pro.orig	2018-11-26 20:18:41 UTC
+++ qwtplot3d.pro
@@ -1,9 +1,9 @@
 # pro file for building the makefile for qwtplot3d
 #
 
-TARGET            = qwtplot3d
+TARGET            = qwtplot3d-qt5
 TEMPLATE          = lib
-CONFIG           += qt warn_on opengl thread zlib debug
+CONFIG           += qt warn_on opengl thread zlib
 MOC_DIR           = tmp
 OBJECTS_DIR       = tmp
 INCLUDEPATH       = include
@@ -11,6 +11,7 @@ DEPENDPATH        = include src
 DESTDIR      			= lib
 #DESTDIR      			= ../../../lib
 QT += opengl
+unix:LIBS +=	-lGLU
 
 win32:TEMPLATE    = vclib
 win32:CONFIG     += dll exceptions
@@ -21,7 +22,7 @@ win32:QMAKE_CXXFLAGS     += $$QMAKE_CFLA
 win32:CONFIG -= zlib
 
 linux-g++:TMAKE_CXXFLAGS += -fno-exceptions
-unix:VERSION = 0.2.6
+unix:VERSION = 0.2.7
 
 # Input
 SOURCES += src/qwt3d_axis.cpp \
@@ -81,8 +82,8 @@ HEADERS += include/qwt3d_surfaceplot.h \
            include/qwt3d_multiplot.h
 
 # gl2ps support
-HEADERS+=3rdparty/gl2ps/gl2ps.h \
-         include/qwt3d_io_gl2ps.h
+# HEADERS+=3rdparty/gl2ps/gl2ps.h \
+HEADERS+=         include/qwt3d_io_gl2ps.h
          
 SOURCES+=src/qwt3d_io_gl2ps.cpp \
          3rdparty/gl2ps/gl2ps.c
@@ -92,4 +93,11 @@ zlib {
   DEFINES += GL2PS_HAVE_ZLIB
   win32:LIBS += zlib.lib
 	unix:LIBS  += -lz
-}
\ No newline at end of file
+}
+
+target.path    = $$[QT_INSTALL_LIBS]
+
+headers.files  = $$HEADERS
+headers.path = $$[QT_INSTALL_HEADERS]/qwtplot3d-qt5
+
+INSTALLS += target headers
