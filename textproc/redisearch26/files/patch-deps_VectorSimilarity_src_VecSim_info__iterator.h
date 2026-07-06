--- deps/VectorSimilarity/src/VecSim/info_iterator.h.orig	2022-11-15 11:19:11 UTC
+++ deps/VectorSimilarity/src/VecSim/info_iterator.h
@@ -6,6 +6,7 @@
 
 #pragma once
 #include <stdlib.h>
+#include <stdint.h>
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -27,7 +28,7 @@ typedef union {
 typedef union {
     double floatingPointValue; // Floating point value. 64 bits float.
     int64_t integerValue;      // Integer value. Signed 64 bits integer.
-    u_int64_t uintegerValue;   // Unsigned value. Unsigned 64 buts integer.
+    uint64_t uintegerValue;   // Unsigned value. Unsigned 64 buts integer.
     const char *stringValue;   // String value.
 } FieldValue;
 
