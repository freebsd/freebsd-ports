--- cmake/modules/csiro.cmake.orig	2015-04-12 10:08:04 UTC
+++ cmake/modules/csiro.cmake
@@ -36,6 +36,10 @@ if(PL_HAVE_QHULL OR WITH_CSA)
       else(CMAKE_C_COMPILER MATCHES "gcc")
         set(NAN_CFLAGS "${NAN_CFLAGS} -ieee")
       endif(CMAKE_C_COMPILER MATCHES "gcc")
+    else(CMAKE_SYSTEM_PROCESSOR MATCHES "alpha.*")
+      if(CMAKE_SYSTEM_PROCESSOR MATCHES "amd64")
+        set(NAN_CFLAGS "${NAN_CFLAGS} -mieee-fp")
+      endif(CMAKE_SYSTEM_PROCESSOR MATCHES "amd64")
     endif(CMAKE_SYSTEM_PROCESSOR MATCHES "alpha.*")
   endif(CMAKE_SYSTEM_PROCESSOR MATCHES "i[0-9]86")
   if(NOT DEFINED NaNAwareCCompiler)
