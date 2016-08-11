--- openjpeg/src/lib/openjp2/opj_includes.h.orig	2015-03-30 08:21:24 UTC
+++ openjpeg/src/lib/openjp2/opj_includes.h
@@ -109,7 +109,7 @@
 
 
 /* Are restricted pointers available? (C99) */
-#if (__STDC_VERSION__ != 199901L)
+#if defined(__STDC_VERSION__) && (__STDC_VERSION__ != 199901L)
 	/* Not a C99 compiler */
 	#ifdef __GNUC__
 		#define restrict __restrict__
