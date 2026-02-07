--- third_party/skia/src/ports/SkMemory_malloc.cpp.orig	2025-12-10 15:04:57 UTC
+++ third_party/skia/src/ports/SkMemory_malloc.cpp
@@ -15,7 +15,7 @@
 
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
-#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX)
+#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__)
 #include <malloc.h>
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
@@ -126,7 +126,7 @@ size_t sk_malloc_size(void* addr, size_t size) {
     #elif defined(SK_BUILD_FOR_ANDROID) && __ANDROID_API__ >= 17
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
-    #elif defined(SK_BUILD_FOR_UNIX)
+    #elif defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__)
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
     #elif defined(SK_BUILD_FOR_WIN)
