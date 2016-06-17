--- openjpeg/libopenjpeg/opj_includes.h.orig	2012-08-08 08:01:36 UTC
+++ openjpeg/libopenjpeg/opj_includes.h
@@ -77,7 +77,7 @@ Most compilers implement their own versi
 #endif /* INLINE */
 
 /* Are restricted pointers available? (C99) */
-#if (__STDC_VERSION__ != 199901L)
+#if defined(__STDC_VERSION__) && (__STDC_VERSION__ != 199901L)
 	/* Not a C99 compiler */
 	#ifdef __GNUC__
 		#define restrict __restrict__
