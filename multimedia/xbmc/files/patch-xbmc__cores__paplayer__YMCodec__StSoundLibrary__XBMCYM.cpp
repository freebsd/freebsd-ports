--- ./xbmc/cores/paplayer/YMCodec/StSoundLibrary/XBMCYM.cpp.orig	2010-10-04 19:46:47.000000000 +0200
+++ ./xbmc/cores/paplayer/YMCodec/StSoundLibrary/XBMCYM.cpp	2010-12-01 12:17:34.217661928 +0100
@@ -25,7 +25,7 @@
 #include <stdio.h>
 #include <stdint.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define __declspec(x)
 #endif
 
