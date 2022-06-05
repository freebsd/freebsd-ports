--- src/3rdparty/webkit/Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	2022-06-05 21:14:42 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/jit/ExecutableAllocator.h
@@ -54,6 +54,10 @@
 #include <unistd.h>
 #endif
 
+#if OS(FREEBSD)
+#include <machine/sysarch.h>
+#endif
+
 #if OS(WINCE)
 // From pkfuncs.h (private header file from the Platform Builder)
 #define CACHE_SYNC_ALL 0x07F
@@ -304,6 +308,13 @@ class ExecutableAllocator { (public)
             :
             : "r" (code), "r" (reinterpret_cast<char*>(code) + size)
             : "r0", "r1", "r2");
+    }
+#elif (CPU(ARM_TRADITIONAL) || CPU(ARM_THUMB2)) && OS(FREEBSD)
+    static void cacheFlush(void *code, size_t size)
+    {
+        struct arm_sync_icache_args asia = { reinterpret_cast<uintptr_t>(code), size };
+
+        sysarch(ARM_SYNC_ICACHE, &asia);
     }
 #elif OS(WINCE)
     static void cacheFlush(void* code, size_t size)
