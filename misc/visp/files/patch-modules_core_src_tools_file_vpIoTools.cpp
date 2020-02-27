--- modules/core/src/tools/file/vpIoTools.cpp.orig	2020-02-22 01:06:07 UTC
+++ modules/core/src/tools/file/vpIoTools.cpp
@@ -85,7 +85,7 @@
 
 // Detect endianness of the host machine
 // Reference: http://www.boost.org/doc/libs/1_36_0/boost/detail/endian.hpp
-#if defined(__GLIBC__) || (defined(__GNUC__) && !defined(__llvm__) && !defined(__MINGW32__) && defined(__BYTE_ORDER__))
+#if defined(__GLIBC__) || (defined(__GNUC__) && !defined(__llvm__) && !defined(__MINGW32__) && defined(__BYTE_ORDER__) && defined(__linux__))
 #include <endian.h>
 #if (__BYTE_ORDER == __LITTLE_ENDIAN)
 #define VISP_LITTLE_ENDIAN
