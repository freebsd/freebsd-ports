--- highwayhash/instruction_sets.h.orig	2024-04-18 09:56:24 UTC
+++ highwayhash/instruction_sets.h
@@ -38,7 +38,11 @@ class InstructionSets {
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
@@ -64,7 +68,7 @@ class InstructionSets {
       Func<HH_TARGET_SSE41>()(std::forward<Args>(args)...);
       return HH_TARGET_SSE41;
     }
-#elif HH_ARCH_PPC
+#elif HH_ARCH_PPC && defined(__LITTLE_ENDIAN__)
     const TargetBits supported = Supported();
     if (supported & HH_TARGET_VSX) {
       Func<HH_TARGET_VSX>()(std::forward<Args>(args)...);
@@ -96,7 +100,7 @@ class InstructionSets {
     if (supported & HH_TARGET_SSE41) {
       Func<HH_TARGET_SSE41>()(std::forward<Args>(args)...);
     }
-#elif HH_ARCH_PPC
+#elif HH_ARCH_PPC && defined(__LITTLE_ENDIAN__)
     if (supported & HH_TARGET_VSX) {
       Func<HH_TARGET_VSX>()(std::forward<Args>(args)...);
     }
