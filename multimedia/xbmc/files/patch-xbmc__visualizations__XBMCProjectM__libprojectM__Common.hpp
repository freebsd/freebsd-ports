--- xbmc/visualizations/XBMCProjectM/libprojectM/Common.hpp.orig	2013-12-27 16:58:27.000000000 +0100
+++ xbmc/visualizations/XBMCProjectM/libprojectM/Common.hpp	2013-12-27 16:58:50.000000000 +0100
@@ -57,11 +57,7 @@
 #endif
 			 
 #ifdef LINUX
-#define projectM_isnan isnan
-#endif
-
-#ifdef LINUX
-#define projectM_isnan isnan
+#define projectM_isnan std::isnan
 #endif
 
 #ifdef WIN32
