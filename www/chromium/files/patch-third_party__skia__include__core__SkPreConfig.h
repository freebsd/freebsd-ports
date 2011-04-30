--- third_party/skia/include/core/SkPreConfig.h.orig	2011-04-16 11:02:02.000000000 +0300
+++ third_party/skia/include/core/SkPreConfig.h	2011-04-25 20:08:55.031145158 +0300
@@ -37,7 +37,7 @@
         #define SK_BUILD_FOR_WIN32
     #elif defined(__SYMBIAN32__)
         #define SK_BUILD_FOR_WIN32
-    #elif defined(linux)
+    #elif defined(linux) || defined(__FreeBSD__)
         #define SK_BUILD_FOR_UNIX
     #elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
         #define SK_BUILD_FOR_IOS
