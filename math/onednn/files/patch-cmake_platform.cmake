--- cmake/platform.cmake.orig	2020-03-31 16:33:27 UTC
+++ cmake/platform.cmake
@@ -95,7 +95,6 @@ elseif(UNIX OR MINGW)
     append(CMAKE_CCXX_NOEXCEPT_FLAGS "-fno-exceptions")
     # compiler specific settings
     if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
-        set(DEF_ARCH_OPT_FLAGS "-msse4.1")
         # Clang cannot vectorize some loops with #pragma omp simd and gets
         # very upset. Tell it that it's okay and that we love it
         # unconditionally.
@@ -144,7 +143,7 @@ elseif(UNIX OR MINGW)
              set(DNNL_ENABLE_JIT_PROFILING CACHE BOOL "OFF" FORCE)
              message(WARNING "AArch64 build, DNNL_ENABLE_JIT_PROFILING is OFF")
         else()
-             set(DEF_ARCH_OPT_FLAGS "-msse4.1")
+             #set(DEF_ARCH_OPT_FLAGS "-msse4.1")
         endif()
         # suppress warning on assumptions made regarding overflow (#146)
         append(CMAKE_CCXX_NOWARN_FLAGS "-Wno-strict-overflow")
