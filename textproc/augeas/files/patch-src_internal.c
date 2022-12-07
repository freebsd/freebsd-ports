--- src/internal.c.orig	2018-08-10 20:17:35 UTC
+++ src/internal.c
@@ -431,7 +431,7 @@ const char *xstrerror(int errnum, char *buf, size_t le
 
 const char *xstrerror(int errnum, char *buf, size_t len) {
 #ifdef HAVE_STRERROR_R
-# ifdef __USE_GNU
+# if defined(__USE_GNU) && defined(__GLIBC__)
     /* Annoying linux specific API contract */
     return strerror_r(errnum, buf, len);
 # else
