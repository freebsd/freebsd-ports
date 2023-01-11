--- third_party/skia/src/core/SkContainers.cpp.orig	2023-01-11 09:17:16 UTC
+++ third_party/skia/src/core/SkContainers.cpp
@@ -13,7 +13,7 @@
 
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
-#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX)
+#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__)
 #include <malloc.h>
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
@@ -37,7 +37,7 @@ SkSpan<std::byte> complete_size(void* ptr, size_t size
     #elif defined(SK_BUILD_FOR_ANDROID) && __ANDROID_API__ >= 17
         completeSize = malloc_usable_size(ptr);
         SkASSERT(completeSize >= size);
-    #elif defined(SK_BUILD_FOR_UNIX)
+    #elif defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__)
         completeSize = malloc_usable_size(ptr);
         SkASSERT(completeSize >= size);
     #elif defined(SK_BUILD_FOR_WIN)
