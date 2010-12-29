--- ./xbmc/cores/DllLoader/exports/util/EmuFileWrapper.h.orig	2010-06-01 16:33:45.000000000 +0200
+++ ./xbmc/cores/DllLoader/exports/util/EmuFileWrapper.h	2010-12-01 12:17:34.211609073 +0100
@@ -29,7 +29,7 @@
 
 class CMutex;
 
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #define _file _fileno
 #endif
 
