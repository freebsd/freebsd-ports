The VSX hash kernel is little-endian only (wrong hashes on big-endian, see
security/highwayhash) and the dispatcher assumes VSX on any PPC64 CPU.
Restores the gate the 9.0.0 update dropped.

--- auxil/highwayhash/highwayhash/instruction_sets.h.orig	2026-09-14 17:24:06 UTC
+++ auxil/highwayhash/highwayhash/instruction_sets.h
@@ -38,7 +38,11 @@
   static TargetBits Supported();
 #elif HH_ARCH_PPC
   static HH_INLINE TargetBits Supported() {
+#ifdef __LITTLE_ENDIAN__
     return HH_TARGET_VSX | HH_TARGET_Portable;
+#else
+    return HH_TARGET_Portable;
+#endif
   }
 #elif HH_ARCH_NEON
   static HH_INLINE TargetBits Supported() {
@@ -64,7 +68,7 @@
       Func<HH_TARGET_SSE41>()(std::forward<Args>(args)...);
       return HH_TARGET_SSE41;
     }
-#elif HH_ARCH_PPC
+#elif HH_ARCH_PPC && defined(__LITTLE_ENDIAN__)
     const TargetBits supported = Supported();
     if (supported & HH_TARGET_VSX) {
       Func<HH_TARGET_VSX>()(std::forward<Args>(args)...);
@@ -96,7 +100,7 @@
     if (supported & HH_TARGET_SSE41) {
       Func<HH_TARGET_SSE41>()(std::forward<Args>(args)...);
     }
-#elif HH_ARCH_PPC
+#elif HH_ARCH_PPC && defined(__LITTLE_ENDIAN__)
     if (supported & HH_TARGET_VSX) {
       Func<HH_TARGET_VSX>()(std::forward<Args>(args)...);
     }
