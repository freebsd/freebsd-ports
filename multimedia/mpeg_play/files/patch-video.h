--- video.h.orig	Wed Oct 25 22:59:38 1995
+++ video.h	Sat Jan 31 03:25:41 2004
@@ -431,7 +431,7 @@
 #define __SCO__ 1
 #endif
 
-#if defined(__i386__) || defined(__VAX__) || defined(__MIPSEL__) || defined(__alpha__) || defined(__SCO__)
+#if defined(__i386__) || defined(__VAX__) || defined(__MIPSEL__) || defined(__alpha__) || defined(__SCO__) || defined(__amd64__)
 #undef  BIG_ENDIAN_ARCHITECTURE
 #define LITTLE_ENDIAN_ARCHITECTURE 1
 #endif
@@ -445,7 +445,7 @@
 Error: Unknown endianism of architecture
 #endif
 
-#ifdef __alpha__
+#if defined(__alpha__) || defined(__amd64__)
 #define SIXTYFOUR_BIT
 #endif
 #endif /* video.h already included */
