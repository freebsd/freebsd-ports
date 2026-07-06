--- deps/VectorSimilarity/src/VecSim/spaces/spaces.h.orig	2026-05-30 14:27:46 UTC
+++ deps/VectorSimilarity/src/VecSim/spaces/spaces.h
@@ -39,6 +39,9 @@
 #if defined(CPU_FEATURES_ARCH_AARCH64)
     using FeaturesType = cpu_features::Aarch64Features;
     constexpr auto getFeatures = cpu_features::GetAarch64Info;
+#elif defined(CPU_FEATURES_ARCH_PPC)
+    using FeaturesType = cpu_features::PPCFeatures;
+    constexpr auto getFeatures = cpu_features::GetPPCInfo;
 #else
     using FeaturesType = cpu_features::X86Features; // Fallback
     constexpr auto getFeatures = cpu_features::GetX86Info;
