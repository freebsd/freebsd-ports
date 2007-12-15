--- ./fitPlugins/fitRational1/fitRational1.pro.orig	2007-10-27 02:15:18.000000000 +0400
+++ ./fitPlugins/fitRational1/fitRational1.pro	2007-11-14 20:19:55.000000000 +0300
@@ -12,9 +12,8 @@
 DESTDIR           = ../
  
 # statically link against GSL in 3rdparty
-INCLUDEPATH += ../../3rdparty/gsl/include/
-LIBS        += ../../3rdparty/gsl/lib/libgsl.a
-LIBS        += ../../3rdparty/gsl/lib/libgslcblas.a
+unix:INCLUDEPATH += $$(LOCALBASE)/include
+unix:LIBS         += -lgsl -lgslcblas
 
 #dynamically link against GSL installed system-wide
 #unix:LIBS += -L /usr/lib$${libsuff} -lgsl -lgslcblas
