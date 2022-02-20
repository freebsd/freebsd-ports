--- skia/ext/SkMemory_new_handler.cpp.orig	2022-02-07 13:39:41 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -78,7 +78,7 @@ static void* malloc_nothrow(size_t size) {
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = malloc(size);
 #else
     // It's the responsibility of the caller to check the return value.
