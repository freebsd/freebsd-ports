--- pread64.h.orig	2024-08-25 11:50:36 UTC
+++ pread64.h
@@ -18,7 +18,7 @@
 # include <sys/reg.h>
 #endif
 
-#if !defined(HAVE_PREAD64) && __WORDSIZE == 64 && !defined(TEST_SYSCALL) && defined(HAVE_PREAD)
+#if defined(__FreeBSD__) || !defined(HAVE_PREAD64) && __WORDSIZE == 64 && !defined(TEST_SYSCALL) && defined(HAVE_PREAD)
 #define pread64 pread
 #define pwrite64 pwrite
 #define HAVE_PREAD64
