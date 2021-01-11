--- H/dlmalloc.h.orig	2021-01-10 12:55:22 UTC
+++ H/dlmalloc.h
@@ -493,7 +493,7 @@ extern Void_t*     sbrk();
   HAVE_USR_INCLUDE_MALLOC_H.
 */
 
-#if HAVE_MALLOC_H && !defined(_WIN32) && !defined(__NetBSD_Version__)
+#if HAVE_MALLOC_H && !defined(_WIN32) && !defined(__NetBSD_Version__) && !defined(__FreeBSD__)
 #define HAVE_USR_INCLUDE_MALLOC_H 1
 #endif
 
