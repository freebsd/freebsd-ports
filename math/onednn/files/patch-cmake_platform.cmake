--- cmake/platform.cmake.orig	2023-11-30 15:53:57 UTC
+++ cmake/platform.cmake
@@ -223,7 +223,7 @@ elseif(UNIX OR MINGW)
                  set(DEF_ARCH_OPT_FLAGS "-O3")
              endif()
              # For native compilation tune for the host processor
-             if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+             if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                  append(DEF_ARCH_OPT_FLAGS "-mcpu=native")
              endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "S390X")
@@ -231,10 +231,10 @@ elseif(UNIX OR MINGW)
                  set(DEF_ARCH_OPT_FLAGS "-O3")
              endif()
              # For native compilation tune for the host processor
-             if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+             if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                  append(DEF_ARCH_OPT_FLAGS "-march=native")
              endif()
-        elseif(DNNL_TARGET_ARCH STREQUAL "X64")
+        elseif(FALSE AND DNNL_TARGET_ARCH STREQUAL "X64")
              set(DEF_ARCH_OPT_FLAGS "-msse4.1")
         endif()
         # Clang cannot vectorize some loops with #pragma omp simd and gets
@@ -325,7 +325,7 @@ elseif(UNIX OR MINGW)
             endif()
             # In GCC, -ftree-vectorize is turned on under -O3 since 2007.
             # For native compilation tune for the host processor
-            if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+            if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                 append(DEF_ARCH_OPT_FLAGS "-mcpu=native")
             endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "S390X")
@@ -334,7 +334,7 @@ elseif(UNIX OR MINGW)
             endif()
             # In GCC, -ftree-vectorize is turned on under -O3 since 2007.
             # For native compilation tune for the host processor
-            if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+            if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                 append(DEF_ARCH_OPT_FLAGS "-march=native")
             endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "RV64")
