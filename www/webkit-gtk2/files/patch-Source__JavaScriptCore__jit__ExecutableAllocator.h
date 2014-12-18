--- Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	2014-10-15 14:25:58 UTC
+++ Source/JavaScriptCore/jit/ExecutableAllocator.h
@@ -223,6 +223,11 @@
         UNUSED_PARAM(size);
 #endif
     }
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+    static void cacheFlush(void* code, size_t size)
+    {
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #else
     #error "The cacheFlush support is missing on this platform."
 #endif
