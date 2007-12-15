--- fitPlugins/fitRational0/fitRational0.pro.orig	2007-10-27 00:15:32.000000000 +0200
+++ fitPlugins/fitRational0/fitRational0.pro	2007-12-15 12:14:56.000000000 +0100
@@ -12,9 +12,8 @@
 DESTDIR           = ../
  
 # statically link against GSL in 3rdparty
-INCLUDEPATH += ../../3rdparty/gsl/include/
-LIBS        += ../../3rdparty/gsl/lib/libgsl.a
-LIBS        += ../../3rdparty/gsl/lib/libgslcblas.a
+unix:INCLUDEPATH += $$(LOCALBASE)/include
+unix:LIBS        += -lgsl -lgslcblas
 
 #dynamically link against GSL installed system-wide
 #unix:LIBS += -L /usr/lib$${libsuff} -lgsl -lgslcblas
