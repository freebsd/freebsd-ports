--- skia/ext/SkMemory_new_handler.cpp.orig	2026-11-17 11:49:09 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -30,7 +30,7 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <malloc.h>
 #endif
 
@@ -87,7 +87,7 @@ void* sk_realloc_throw(void* addr, size_t size) {
       old_size = _msize(addr);
 #elif BUILDFLAG(IS_APPLE)
       old_size = malloc_size(addr);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && !BUILDFLAG(IS_OPENBSD)
       old_size = malloc_usable_size(addr);
 #endif
     }
@@ -125,7 +125,7 @@ static void* malloc_nothrow(size_t size, int debug_sen
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
