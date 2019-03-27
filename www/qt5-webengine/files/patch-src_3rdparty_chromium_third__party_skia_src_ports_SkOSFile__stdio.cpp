--- src/3rdparty/chromium/third_party/skia/src/ports/SkOSFile_stdio.cpp.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/skia/src/ports/SkOSFile_stdio.cpp
@@ -129,7 +129,7 @@ void sk_fflush(FILE* f) {
 
 void sk_fsync(FILE* f) {
 #if !defined(_WIN32) && !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) \
-        && !defined(_NEWLIB_VERSION)
+        && !defined(_NEWLIB_VERSION) && !defined(__FreeBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
