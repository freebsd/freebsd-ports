--- src/htsglobal.h.orig	Sat Oct 11 08:54:59 2003
+++ src/htsglobal.h	Tue Feb 24 15:50:40 2004
@@ -120,10 +120,8 @@
 #else
 
 #define HTS_WIN 0
-#ifdef __linux
 #undef HTS_PLATFORM
 #define HTS_PLATFORM 3
-#endif
 #endif
 
 // compatibilité DOS
