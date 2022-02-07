--- cmake/FindUnwind.cmake.orig	2022-02-07 18:57:25 UTC
+++ cmake/FindUnwind.cmake
@@ -19,9 +19,9 @@ elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR
     set (Unwind_ARCH "unwind-x86_64" "unwind-x86")
 elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$")
     set (Unwind_ARCH "unwind-x86" "unwind-x86_64")
-elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc64")
+elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^(powerpc64|ppc64)")
     set (Unwind_ARCH "unwind-ppc64")
-elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc")
+elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^(powerpc|ppc)")
     set (Unwind_ARCH "unwind-ppc32")
 elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^mips")
     set (Unwind_ARCH "unwind-mips")
