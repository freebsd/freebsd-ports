--- video.h.orig	1995-10-25 21:59:38 UTC
+++ video.h
@@ -431,21 +431,23 @@ extern unsigned int cacheMiss[8][8];
 #define __SCO__ 1
 #endif
 
-#if defined(__i386__) || defined(__VAX__) || defined(__MIPSEL__) || defined(__alpha__) || defined(__SCO__)
+/* XXX: conditions below were simplified for FreeBSD */
+
+#if defined(__i386__) || defined(__amd64__)
 #undef  BIG_ENDIAN_ARCHITECTURE
 #define LITTLE_ENDIAN_ARCHITECTURE 1
 #endif
 
-#if defined(__RS6000__) || defined(__SPARC__) || defined(__680x0__) || defined(__HPUX__) || defined(__MIPSEB__) || defined(convex) || defined(__convex__)
+#if defined(__powerpc__) || defined(__sparc__)
 #undef  LITTLE_ENDIAN_ARCHITECTURE
 #define BIG_ENDIAN_ARCHITECTURE 1
 #endif
 
 #if !defined(LITTLE_ENDIAN_ARCHITECTURE) && !defined(BIG_ENDIAN_ARCHITECTURE)
-Error: Unknown endianism of architecture
+#error Unknown endianness of architecture
 #endif
 
-#ifdef __alpha__
+#if defined(__amd64__) || defined(__powerpc64__) || defined(__sparc64__)
 #define SIXTYFOUR_BIT
 #endif
 #endif /* video.h already included */
