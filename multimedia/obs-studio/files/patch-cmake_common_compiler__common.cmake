# disable IPO due to breakage:
# ld: error: relocation R_X86_64_PC32 cannot be used against symbol '__stack_chk_guard'; recompile with -fPIC

--- cmake/common/compiler_common.cmake.orig	2025-01-06 17:00:00 UTC
+++ cmake/common/compiler_common.cmake
@@ -28,8 +28,8 @@ if(HAS_INTERPROCEDURAL_OPTIMIZATION)
   message(STATUS "Checking for interprocedural optimization support - enabled [Release, MinSizeRel]")
   set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF)
   set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO OFF)
-  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
-  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL ON)
+  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE OFF)
+  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL OFF)
 else()
   message(STATUS "Checking for interprocedural optimization support - disabled")
   set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF)

