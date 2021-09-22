--- Source/JavaScriptCore/jit/ExecutableAllocator.cpp.orig	2021-09-22 23:05:58 UTC
+++ Source/JavaScriptCore/jit/ExecutableAllocator.cpp
@@ -95,7 +95,7 @@ namespace JSC {
 
 using namespace WTF;
 
-#if defined(FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB) && FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB > 0
+#if defined(FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB) && FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB > 0 && !defined(__aarch64__)
 static constexpr size_t fixedExecutableMemoryPoolSize = FIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB * MB;
 #elif CPU(ARM)
 static constexpr size_t fixedExecutableMemoryPoolSize = 16 * MB;
