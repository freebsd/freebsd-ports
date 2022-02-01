--- third_party/blink/renderer/platform/wtf/math_extras.h.orig	2022-01-24 12:24:17 UTC
+++ third_party/blink/renderer/platform/wtf/math_extras.h
@@ -127,11 +127,11 @@ constexpr float Grad2turn(float g) {
   return g * (1.0f / 400.0f);
 }
 
-constexpr double RoundHalfTowardsPositiveInfinity(double value) {
+inline double RoundHalfTowardsPositiveInfinity(double value) {
   return std::floor(value + 0.5);
 }
 
-constexpr float RoundHalfTowardsPositiveInfinity(float value) {
+inline float RoundHalfTowardsPositiveInfinity(float value) {
   return std::floor(value + 0.5f);
 }
 
