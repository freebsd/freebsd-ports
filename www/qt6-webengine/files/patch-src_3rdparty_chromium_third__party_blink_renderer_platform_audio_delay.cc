--- src/3rdparty/chromium/third_party/blink/renderer/platform/audio/delay.cc.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/audio/delay.cc
@@ -107,8 +107,8 @@ std::tuple<size_t, size_t> Delay::ProcessARateVector(
 #if !(defined(ARCH_CPU_X86_FAMILY) || defined(CPU_ARM_NEON))
 // Default scalar versions if simd/neon are not available.
 std::tuple<size_t, size_t> Delay::ProcessARateVector(
-    float* destination,
-    uint32_t frames_to_process) const {
+    base::span<float> destination,
+    size_t frames_to_process) const {
   // We don't have a vectorized version, so just do nothing and return the 0 to
   // indicate no frames processed and return the current write_index_.
   return std::make_tuple(0, write_index_);
