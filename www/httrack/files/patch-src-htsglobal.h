--- src/htsglobal.h	Sat Jun  4 15:09:01 2005
+++ src/htsglobal.h.orig	Thu Oct 13 11:02:26 2005
@@ -173,10 +173,8 @@
 #else
 
 #define HTS_WIN 0
-#ifdef __linux
 #undef HTS_PLATFORM
 #define HTS_PLATFORM 3
-#endif
 #endif
 
 // don't spare memory usage by default
