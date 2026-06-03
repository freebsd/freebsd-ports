--- skia/ext/SkMemory_new_handler.cpp.orig	2026-04-15 12:07:04 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -22,7 +22,7 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <malloc.h>
 #endif
 
@@ -108,7 +108,7 @@ static void* malloc_nothrow(size_t size, int debug_sen
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
