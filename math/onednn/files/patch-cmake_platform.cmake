--- cmake/platform.cmake.orig	2024-06-11 23:20:12 UTC
+++ cmake/platform.cmake
@@ -242,7 +242,7 @@ elseif(UNIX OR MINGW)
                  set(DEF_ARCH_OPT_FLAGS "-O3")
              endif()
              # For native compilation tune for the host processor
-             if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+             if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                  append(DEF_ARCH_OPT_FLAGS "-mcpu=native")
              endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "S390X")
@@ -250,7 +250,7 @@ elseif(UNIX OR MINGW)
                  set(DEF_ARCH_OPT_FLAGS "-O3")
              endif()
              # For native compilation tune for the host processor
-             if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+	     if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                  append(DEF_ARCH_OPT_FLAGS "-march=native")
              endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "X64")
@@ -348,7 +348,7 @@ elseif(UNIX OR MINGW)
             endif()
             # In GCC, -ftree-vectorize is turned on under -O3 since 2007.
             # For native compilation tune for the host processor
-            if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+            if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                 append(DEF_ARCH_OPT_FLAGS "-mcpu=native")
             endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "S390X")
@@ -357,7 +357,7 @@ elseif(UNIX OR MINGW)
             endif()
             # In GCC, -ftree-vectorize is turned on under -O3 since 2007.
             # For native compilation tune for the host processor
-            if (CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
+            if (FALSE AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
                 append(DEF_ARCH_OPT_FLAGS "-march=native")
             endif()
         elseif(DNNL_TARGET_ARCH STREQUAL "RV64")
