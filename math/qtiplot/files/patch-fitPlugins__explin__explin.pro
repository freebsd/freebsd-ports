--- ./fitPlugins/explin/explin.pro.orig	2009-03-05 15:56:56.000000000 +0300
+++ ./fitPlugins/explin/explin.pro	2009-03-26 23:10:01.000000000 +0300
@@ -12,14 +12,13 @@
 DESTDIR           = ../
  
 # statically link against GSL in 3rdparty
-INCLUDEPATH += ../../3rdparty/gsl/include/
-LIBS        += ../../3rdparty/gsl/lib/libgsl.a
-LIBS        += ../../3rdparty/gsl/lib/libgslcblas.a
+unix:INCLUDEPATH += $$(LOCALBASE)/include
+unix:LIBS        += -lgsl -lgslcblas
 
 #dynamically link against GSL installed system-wide
 #unix:LIBS += -L /usr/lib$${libsuff} -lgsl -lgslcblas
 
-target.path=/usr/lib$${libsuff}/qtiplot/plugins
+target.path=$$PREFIX/share/qtiplot/fitPlugins
 INSTALLS += target
 
 SOURCES += explin.c
