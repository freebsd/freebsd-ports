--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/math_extras.h.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/math_extras.h
@@ -128,6 +128,10 @@ constexpr float Grad2turn(float g) {
   return g * (1.0f / 400.0f);
 }
 
+#if defined(OS_FREEBSD)
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Winvalid-constexpr"
+#endif
 inline double RoundHalfTowardsPositiveInfinity(double value) {
   return std::floor(value + 0.5);
 }
@@ -135,6 +139,9 @@ inline float RoundHalfTowardsPositiveInfinity(float va
 inline float RoundHalfTowardsPositiveInfinity(float value) {
   return std::floor(value + 0.5f);
 }
+#if defined(OS_FREEBSD)
+#pragma clang diagnostic pop
+#endif
 
 // ClampTo() is implemented by templated helper classes (to allow for partial
 // template specialization) as well as several helper functions.
