--- Source/JavaScriptCore/jit/ExecutableAllocator.cpp.orig	2021-02-07 10:45:05 UTC
+++ Source/JavaScriptCore/jit/ExecutableAllocator.cpp
@@ -76,7 +76,7 @@ namespace JSC {
 
 using namespace WTF;
 
-#if defined(FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB) && FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB > 0
+#if defined(FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB) && FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB > 0 && !defined(__aarch64__)
 static constexpr size_t fixedExecutableMemoryPoolSize = FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB * MB;
 #elif CPU(ARM)
 static constexpr size_t fixedExecutableMemoryPoolSize = 16 * MB;
