- FreeBSD and NetBSD powerpc* targets don't abbreviate to ppc*

--- build/cmake/aom_configure.cmake.orig	2023-08-14 21:22:47 UTC
+++ build/cmake/aom_configure.cmake
@@ -75,7 +75,7 @@ if(NOT AOM_TARGET_CPU)
     set(AOM_TARGET_CPU "${cpu_lowercase}")
   elseif(cpu_lowercase MATCHES "aarch64")
     set(AOM_TARGET_CPU "arm64")
-  elseif(cpu_lowercase MATCHES "^ppc")
+  elseif(cpu_lowercase MATCHES "^ppc|^powerpc")
     set(AOM_TARGET_CPU "ppc")
   else()
     message(WARNING "The architecture ${CMAKE_SYSTEM_PROCESSOR} is not "
