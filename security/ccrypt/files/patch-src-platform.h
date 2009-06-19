--- src/platform.h.orig	2009-06-05 07:39:49.000000000 -0700
+++ src/platform.h	2009-06-10 17:18:40.000000000 -0700
@@ -78,9 +78,6 @@
 
 #else /* on a POSIX system, map these to no-ops */
 
-static inline void setmode(int fd, int mode) {
-  return;
-}
 #ifndef O_BINARY
 #define O_BINARY 0
 #endif /* O_BINARY */
