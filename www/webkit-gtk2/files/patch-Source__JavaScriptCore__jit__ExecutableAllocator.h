

--- Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	2014-12-25 12:52:32.786521149 +0100
+++ Source/JavaScriptCore/jit/ExecutableAllocator.h	2014-12-25 12:52:41.921520911 +0100
@@ -104,7 +104,8 @@
 #if ENABLE(EXECUTABLE_ALLOCATOR_FIXED)
 #if CPU(ARM) || CPU(ARM64)
 static const size_t fixedExecutableMemoryPoolSize = 16 * 1024 * 1024;
-#elif CPU(X86_64)
+// We don't want an initial allocation of 1GB, it's above the default ulimit
+#elif CPU(X86_64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 static const size_t fixedExecutableMemoryPoolSize = 1024 * 1024 * 1024;
 #else
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;
@@ -146,6 +147,11 @@
     {
         reprotectRegion(start, size, Executable);
     }
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+    static void cacheFlush(void* code, size_t size)
+    {
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #else
     static void makeWritable(void*, size_t) {}
     static void makeExecutable(void*, size_t) {}
