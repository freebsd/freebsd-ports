--- third_party/skia/src/ports/SkOSFile_stdio.cpp.orig	2017-08-10 02:10:46.427948000 +0200
+++ third_party/skia/src/ports/SkOSFile_stdio.cpp	2017-08-10 02:11:15.515911000 +0200
@@ -117,7 +117,7 @@
 
 void sk_fsync(FILE* f) {
 #if !defined(_WIN32) && !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) \
-        && !defined(_NEWLIB_VERSION)
+        && !defined(_NEWLIB_VERSION) && !defined(__FreeBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
