--- ./fitPlugins/fitRational0/fitRational0.pro.orig	Thu Apr 19 15:36:12 2007
+++ ./fitPlugins/fitRational0/fitRational0.pro	Sat Jun  2 15:33:23 2007
@@ -11,9 +11,8 @@
 
 DESTDIR           = ../
  
-INCLUDEPATH += ../../3rdparty/gsl
-LIBS        += ../../3rdparty/gsl/lib/libgsl.a
-LIBS        += ../../3rdparty/gsl/lib/libgslcblas.a
+unix:INCLUDEPATH += $$(LOCALBASE)/include
+unix:LIBS         += -lgsl -lgslcblas
 
 #target.path=/usr/lib$${libsuff}
 #INSTALLS += target
