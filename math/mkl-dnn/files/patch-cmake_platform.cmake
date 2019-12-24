--- cmake/platform.cmake.orig	2019-12-24 01:47:09 UTC
+++ cmake/platform.cmake
@@ -89,7 +89,6 @@ elseif(UNIX OR MINGW)
     append(CMAKE_CCXX_NOEXCEPT_FLAGS "-fno-exceptions")
     # compiler specific settings
     if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
-        set(DEF_ARCH_OPT_FLAGS "-msse4.1")
         # Clang cannot vectorize some loops with #pragma omp simd and gets
         # very upset. Tell it that it's okay and that we love it
         # unconditionally.
@@ -133,7 +132,6 @@ elseif(UNIX OR MINGW)
             append(CMAKE_CCXX_SANITIZER_FLAGS "-g -fno-omit-frame-pointer")
         endif()
     elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
-        set(DEF_ARCH_OPT_FLAGS "-msse4.1")
         # suppress warning on assumptions made regarding overflow (#146)
         append(CMAKE_CCXX_NOWARN_FLAGS "-Wno-strict-overflow")
     elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
