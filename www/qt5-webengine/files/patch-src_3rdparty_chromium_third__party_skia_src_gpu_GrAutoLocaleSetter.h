--- src/3rdparty/chromium/third_party/skia/src/gpu/GrAutoLocaleSetter.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/skia/src/gpu/GrAutoLocaleSetter.h
@@ -27,7 +27,7 @@
 #define HAVE_XLOCALE 0
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__FreeBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1
