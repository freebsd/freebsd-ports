--- openjpeg/libopenjpeg/opj_includes.h.orig	2012-02-13 08:48:33.000000000 +0900
+++ openjpeg/libopenjpeg/opj_includes.h	2012-02-13 08:50:41.000000000 +0900
@@ -77,7 +77,7 @@
 #endif /* INLINE */
 
 /* Are restricted pointers available? (C99) */
-#if (__STDC_VERSION__ != 199901L)
+#if defined(__STDC_VERSION__) && (__STDC_VERSION__ != 199901L)
 	/* Not a C99 compiler */
 	#ifdef __GNUC__
 		#define restrict __restrict__
