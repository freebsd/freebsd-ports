--- openjpeg/libopenjpeg/opj_malloc.h.orig	2012-02-08 17:48:48.000000000 +0900
+++ openjpeg/libopenjpeg/opj_malloc.h	2012-02-13 11:12:27.000000000 +0900
@@ -83,6 +83,8 @@
 #else /* Not _WIN32 */
 	#if defined(__sun)
 		#define HAVE_MEMALIGN
+	#elif defined(__FreeBSD__)
+		#undef HAVE_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__)	
 		#define HAVE_MEMALIGN
