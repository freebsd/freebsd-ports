--- ./fitPlugins/fitRational1/fitRational1.pro.orig	Wed Jun 13 21:16:56 2007
+++ ./fitPlugins/fitRational1/fitRational1.pro	Sat Jul 14 14:56:13 2007
@@ -12,9 +12,8 @@
 DESTDIR           = ../
  
 # statically link against GSL in 3rdparty
-INCLUDEPATH += ../../3rdparty/gsl
-LIBS         += ../3rdparty/gsl/lib/libgsl.a
-LIBS         += ../3rdparty/gsl/lib/libgslcblas.a
+unix:INCLUDEPATH += $$(LOCALBASE)/include
+unix:LIBS         += -lgsl -lgslcblas
 #dynamically link against GSL installed system-wide
 #unix:LIBS += -L /usr/lib$${libsuff} -lgsl -lgslcblas
 
