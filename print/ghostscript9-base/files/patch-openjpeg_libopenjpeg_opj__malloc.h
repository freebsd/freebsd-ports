--- openjpeg/libopenjpeg/opj_malloc.h.orig	2012-08-08 08:01:36 UTC
+++ openjpeg/libopenjpeg/opj_malloc.h
@@ -83,6 +83,8 @@ Allocate memory aligned to a 16 byte bou
 #else /* Not _WIN32 */
 	#if defined(__sun)
 		#define HAVE_MEMALIGN
+	#elif defined(__FreeBSD__)
+		#undef HAVE_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__) && !defined(_AIX) && !defined(__FreeBSD__)
 		#define HAVE_MEMALIGN
