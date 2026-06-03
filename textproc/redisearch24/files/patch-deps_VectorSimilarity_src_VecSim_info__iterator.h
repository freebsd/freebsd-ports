--- deps/VectorSimilarity/src/VecSim/info_iterator.h.orig	2026-05-30 19:16:13 UTC
+++ deps/VectorSimilarity/src/VecSim/info_iterator.h
@@ -1,5 +1,6 @@
 #pragma once
 #include <stdlib.h>
+#include <stdint.h>
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -30,7 +31,7 @@ typedef struct {
     union {
         double floatingPointValue; // Floating point value. 64 bits float.
         int64_t integerValue;      // Integer value. Signed 64 bits integer.
-        u_int64_t uintegerValue;   // Unsigned value. Unsigned 64 buts integer.
+        uint64_t uintegerValue;   // Unsigned value. Unsigned 64 buts integer.
         const char *stringValue;   // String value.
     };
 } VecSim_InfoField;
