--- lib/libflatarray/src/aligned_allocator.hpp.orig	2014-10-28 09:12:48 UTC
+++ lib/libflatarray/src/aligned_allocator.hpp
@@ -8,13 +8,7 @@
 #ifndef FLAT_ARRAY_ALIGNED_ALLOCATOR_HPP
 #define FLAT_ARRAY_ALIGNED_ALLOCATOR_HPP
 
-#ifdef __APPLE__
 #include <cstddef>
-#include <stdlib.h>
-#else
-#include <malloc.h>
-#endif
-
 #include <memory>
 
 namespace LibFlatArray {
