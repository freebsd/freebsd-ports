--- ./xbmc/cores/paplayer/NSFCodec/NoseFartDLL.cpp.orig	2010-10-04 19:49:31.000000000 +0200
+++ ./xbmc/cores/paplayer/NSFCodec/NoseFartDLL.cpp	2010-12-01 12:17:34.222702947 +0100
@@ -19,7 +19,7 @@
  *
  */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define __declspec(x) 
 #endif
 extern "C" 
