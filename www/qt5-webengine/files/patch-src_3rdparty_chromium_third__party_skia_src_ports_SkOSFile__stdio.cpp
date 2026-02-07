--- src/3rdparty/chromium/third_party/skia/src/ports/SkOSFile_stdio.cpp.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/skia/src/ports/SkOSFile_stdio.cpp
@@ -132,7 +132,7 @@ void sk_fsync(FILE* f) {
 
 void sk_fsync(FILE* f) {
 #if !defined(_WIN32) && !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) \
-        && !defined(_NEWLIB_VERSION)
+        && !defined(_NEWLIB_VERSION) && !defined(__FreeBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
