--- lib/fuse-zip.cpp.orig	2013-07-15 16:25:13.000000000 +0400
+++ lib/fuse-zip.cpp	2013-07-15 16:25:37.000000000 +0400
@@ -426,19 +426,11 @@
     return 0;
 }
 
-#if ( __FreeBSD__ >= 10 )
-int fusezip_setxattr(const char *, const char *, const char *, size_t, int, uint32_t) {
-#else
 int fusezip_setxattr(const char *, const char *, const char *, size_t, int) {
-#endif
     return -ENOTSUP;
 }
 
-#if ( __FreeBSD__ >= 10 )
-int fusezip_getxattr(const char *, const char *, char *, size_t, uint32_t) {
-#else
 int fusezip_getxattr(const char *, const char *, char *, size_t) {
-#endif
     return -ENOTSUP;
 }
 
