--- cmake/modules/csiro.cmake.orig	2009-09-06 21:04:43.000000000 +0200
+++ cmake/modules/csiro.cmake	2009-12-30 21:10:58.000000000 +0100
@@ -36,6 +36,10 @@
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
