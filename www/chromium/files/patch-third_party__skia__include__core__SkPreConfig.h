--- third_party/skia/include/core/SkPreConfig.h.orig	2011-11-01 10:43:44.000000000 +0200
+++ third_party/skia/include/core/SkPreConfig.h	2011-11-21 22:31:26.000000000 +0200
@@ -30,7 +30,7 @@
         #define SK_BUILD_FOR_WIN32
     #elif defined(__SYMBIAN32__)
         #define SK_BUILD_FOR_WIN32
-    #elif defined(linux) || defined(__OpenBSD_)
+    #elif defined(linux) || defined(__OpenBSD_) || defined(__FreeBSD__)
         #define SK_BUILD_FOR_UNIX
     #elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
         #define SK_BUILD_FOR_IOS
