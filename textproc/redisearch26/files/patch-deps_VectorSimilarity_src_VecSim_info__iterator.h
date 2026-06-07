--- deps/VectorSimilarity/src/VecSim/info_iterator.h.orig	2022-10-20 13:03:07 UTC
+++ deps/VectorSimilarity/src/VecSim/info_iterator.h
@@ -1,5 +1,6 @@
 #pragma once
 #include <stdlib.h>
+#include <stdint.h>
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -21,7 +22,7 @@ typedef union {
 typedef union {
     double floatingPointValue; // Floating point value. 64 bits float.
     int64_t integerValue;      // Integer value. Signed 64 bits integer.
-    u_int64_t uintegerValue;   // Unsigned value. Unsigned 64 buts integer.
+    uint64_t uintegerValue;   // Unsigned value. Unsigned 64 buts integer.
     const char *stringValue;   // String value.
 } FieldValue;
 
