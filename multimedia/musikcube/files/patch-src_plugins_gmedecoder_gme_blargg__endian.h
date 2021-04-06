--- src/plugins/gmedecoder/gme/blargg_endian.h.orig	2021-04-05 20:58:30 UTC
+++ src/plugins/gmedecoder/gme/blargg_endian.h
@@ -34,9 +34,7 @@
 #if defined (LSB_FIRST) || defined (__LITTLE_ENDIAN__) || BLARGG_CPU_X86 || \
 		(defined (LITTLE_ENDIAN) && LITTLE_ENDIAN+0 != 1234)
 	#define BLARGG_LITTLE_ENDIAN 1
-#endif
-
-#if defined (MSB_FIRST)     || defined (__BIG_ENDIAN__) || defined (WORDS_BIGENDIAN) || \
+#elif defined (MSB_FIRST)     || defined (__BIG_ENDIAN__) || defined (WORDS_BIGENDIAN) || \
 	defined (__sparc__)     ||  BLARGG_CPU_POWERPC || \
 	(defined (BIG_ENDIAN) && BIG_ENDIAN+0 != 4321)
 	#define BLARGG_BIG_ENDIAN 1
