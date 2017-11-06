--- src/3rdparty/webkit/Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	2017-01-05 13:47:51 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/jit/ExecutableAllocator.h
@@ -326,6 +326,8 @@ public:
         syscall(__NR_cacheflush, reinterpret_cast<unsigned>(code), size, CACHEFLUSH_D_WB | CACHEFLUSH_I);
 #endif
     }
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+       __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
     #error "The cacheFlush support is missing on this platform."
 #endif
