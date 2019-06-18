--- third_party/skia/src/ports/SkOSFile_stdio.cpp.orig	2019-03-11 22:08:28 UTC
+++ third_party/skia/src/ports/SkOSFile_stdio.cpp
@@ -129,7 +129,7 @@ void sk_fflush(FILE* f) {
 
 void sk_fsync(FILE* f) {
 #if !defined(_WIN32) && !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) \
-        && !defined(_NEWLIB_VERSION)
+        && !defined(_NEWLIB_VERSION) && !defined(__FreeBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
