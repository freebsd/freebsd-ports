--- src/tools/fdsdump/src/aggregator/hashTable.cpp.orig	2024-10-15 16:33:15 UTC
+++ src/tools/fdsdump/src/aggregator/hashTable.cpp
@@ -6,7 +6,11 @@
 
 #define XXH_INLINE_ALL
 
+#if defined(__arm__) || defined(__aarch64__)
+#include <sse2neon.h>
+#else
 #include <xmmintrin.h>
+#endif
 
 #include "hashTable.hpp"
 #include "3rd_party/xxhash/xxhash.h"
