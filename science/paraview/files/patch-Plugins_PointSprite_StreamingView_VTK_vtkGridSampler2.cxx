--- Plugins/StreamingView/VTK/vtkGridSampler2.cxx.orig	2011-04-01 13:42:14.000000000 +0700
+++ Plugins/StreamingView/VTK/vtkGridSampler2.cxx	2011-04-01 13:48:03.000000000 +0700
@@ -21,7 +21,7 @@
 
 #include <math.h>
 
-#ifdef WIN32
+#if defined(WIN32) || defined(__FreeBSD__)
   double log2(double value)
   {
     return log(value)/log(2.0);
