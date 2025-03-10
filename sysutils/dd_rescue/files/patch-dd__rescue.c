--- dd_rescue.c.orig	2024-08-22 17:41:01 UTC
+++ dd_rescue.c
@@ -144,12 +144,11 @@
 # include <fallocate.h>
 #else
 # ifdef HAVE_FALLOCATE64
-#  include <linux/falloc.h>
 typedef off64_t __off64_t;
 # endif
 #endif
 
-#if defined(HAVE_DLFCN_H) && !defined(NO_LIBDL)
+#if defined(HAVE_DLFCN_H) && !defined(NO_LIBDL) && !defined(__FreeBSD__)
 #include <dlfcn.h>
 void* libfalloc = (void*)0;
 #define USE_LIBDL 1
@@ -177,7 +176,7 @@ void* libfalloc = (void*)0;
 #endif
 
 /* Handle lack of stat64 */
-#ifdef HAVE_STAT64
+#if defined(HAVE_STAT64) && !defined(__FreeBSD__)
 # define STAT64 stat64
 # define FSTAT64 fstat64
 #else
@@ -186,17 +185,17 @@ void* libfalloc = (void*)0;
 # warning We lack stat64, may not handle >2GB files correctly
 #endif
 
-#ifndef HAVE_LSEEK64
+#if !defined(HAVE_LSEEK64) || defined(__FreeBSD__)
 # define lseek64 lseek
 # warning We lack lseek64, may not handle >2GB files correctly
 #endif
 
 /* This is not critical -- most platforms have an internal 64bit offset with plain open() */
-#ifndef HAVE_OPEN64
+#if !defined(HAVE_OPEN64 ) || defined(__FreeBSD__)
 # define open64 open
 #endif
 
-#if !defined(HAVE_PREAD64) || defined(TEST_SYSCALL)
+#if !defined(HAVE_PREAD64) || defined(TEST_SYSCALL) || defined(__FreeBSD__)
 #include "pread64.h"
 #endif
 
@@ -698,7 +697,7 @@ static void unload_plugins() {};
 static void unload_plugins() {};
 #endif
 
-#if defined(HAVE_POSIX_FADVISE) && !defined(HAVE_POSIX_FADVISE64)
+#if defined(HAVE_POSIX_FADVISE) && !defined(HAVE_POSIX_FADVISE64) || defined(__FreeBSD__)
 #define posix_fadvise64 posix_fadvise
 #endif
 #ifdef HAVE_POSIX_FADVISE
@@ -1055,13 +1054,13 @@ static void do_fallocate(int fd, const char* onm, opt_
 				op->init_opos, to_falloc);
 #ifdef HAVE_FALLOCATE64
 	else
-		rc = fallocate64(fd, 1, op->init_opos, to_falloc);
+		rc = posix_fallocate(fd, op->init_opos, to_falloc);
 #endif
 #elif defined(HAVE_LIBFALLOCATE)
 	rc = linux_fallocate64(fd, FALLOC_FL_KEEP_SIZE, 
 			      op->init_opos, to_falloc);
 #else /* HAVE_FALLOCATE64 */
-	rc = fallocate64(fd, 1, op->init_opos, to_falloc);
+	rc = posix_fallocate(fd, op->init_opos, to_falloc);
 #endif
 	if (rc)
 	       fplog(stderr, WARN, "fallocate %s (%sk, %sk) failed: %s\n",
