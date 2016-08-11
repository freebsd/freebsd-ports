--- skia/ext/SkMemory_new_handler.cpp.orig	2016-04-08 16:02:10 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -62,7 +62,7 @@ static void* sk_malloc_nothrow(size_t si
     // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
     // doesn't work as intended everywhere.
     void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_FREEBSD)
     result = malloc(size);
 #else
     // It's the responsibility of the caller to check the return value.
@@ -89,7 +89,7 @@ void* sk_calloc(size_t size) {
     // TODO(b.kelemen): we should always use UncheckedCalloc but currently it
     // doesn't work as intended everywhere.
     void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_FREEBSD)
     result = calloc(1, size);
 #else
     // It's the responsibility of the caller to check the return value.
