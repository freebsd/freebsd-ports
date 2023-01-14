--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/math_extras.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/math_extras.h
@@ -134,6 +134,9 @@ inline float RoundHalfTowardsPositiveInfinity(float va
 inline float RoundHalfTowardsPositiveInfinity(float value) {
   return std::floor(value + 0.5f);
 }
+#if defined(OS_FREEBSD)
+#pragma clang diagnostic pop
+#endif
 
 // ClampTo() is implemented by templated helper classes (to allow for partial
 // template specialization) as well as several helper functions.
