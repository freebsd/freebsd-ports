--- deps/VectorSimilarity/src/VecSim/spaces/spaces.h.orig	2026-10-18 15:13:16 UTC
+++ deps/VectorSimilarity/src/VecSim/spaces/spaces.h
@@ -36,9 +36,15 @@ static inline auto getCpuOptimizationFeatures(const vo
 #if defined(CPU_FEATURES_ARCH_AARCH64)
     using FeaturesType = cpu_features::Aarch64Features;
     constexpr auto getFeatures = cpu_features::GetAarch64Info;
-#else
-    using FeaturesType = cpu_features::X86Features; // Fallback
+#elif defined(CPU_FEATURES_ARCH_X86_64)
+    using FeaturesType = cpu_features::X86Features;
     constexpr auto getFeatures = cpu_features::GetX86Info;
+#else
+    // No architecture-specific implementations exist for this CPU: there are
+    // no features to detect and the generic implementation is always chosen.
+    struct FeaturesType {};
+    struct NoFeaturesInfo { FeaturesType features; };
+    constexpr auto getFeatures = []() { return NoFeaturesInfo{}; };
 #endif
     return arch_opt ? *static_cast<const FeaturesType *>(arch_opt) : getFeatures().features;
 }
