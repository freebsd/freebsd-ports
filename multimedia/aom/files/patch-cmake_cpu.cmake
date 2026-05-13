- Don't enable NEON on armv6 similar to build/cmake/rtcd.pl

--- cmake/cpu.cmake.orig	2026-05-13 23:13:38 UTC
+++ cmake/cpu.cmake
@@ -86,7 +86,7 @@ svfloat32_t func(svfloat32_t a) {
     endif()
   endforeach()
 
-elseif("${AOM_TARGET_CPU}" MATCHES "^arm")
+elseif("${AOM_TARGET_CPU}" MATCHES "^arm" AND NOT "${AOM_TARGET_CPU}" MATCHES "^armv6")
   set(AOM_ARCH_ARM 1)
 
   if(ENABLE_NEON)
