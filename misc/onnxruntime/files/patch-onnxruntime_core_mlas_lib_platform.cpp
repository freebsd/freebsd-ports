--- onnxruntime/core/mlas/lib/platform.cpp.orig	2025-06-26 13:24:10 UTC
+++ onnxruntime/core/mlas/lib/platform.cpp
@@ -611,6 +611,11 @@ --*/
     bool HasP9Instructions = hwcap2 & PPC_FEATURE2_ARCH_3_00;
 #elif defined(_AIX)
     bool HasP9Instructions = __power_9_andup();
+#elif defined(__FreeBSD__)
+    unsigned long hwcap2;
+    elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+
+    bool HasP9Instructions = hwcap2 & PPC_FEATURE2_ARCH_3_00;
 #endif // __linux__
     if (HasP9Instructions) {
         this->QuantizeLinearS8Kernel = MlasQuantizeLinearS8KernelVSX;
@@ -624,6 +629,11 @@ --*/
     bool HasP10Instructions = ((hwcap2 & PPC_FEATURE2_MMA) && (hwcap2 & PPC_FEATURE2_ARCH_3_1));
 #elif defined(_AIX)
     bool HasP10Instructions = (__power_10_andup() && __power_mma_version() == MMA_V31);
+#elif defined(__FreeBSD__)
+    unsigned long hwcap2;
+    elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+
+    bool HasP10Instructions = ((hwcap2 & PPC_FEATURE2_MMA) && (hwcap2 & PPC_FEATURE2_ARCH_3_1));
 #endif // __linux__
     if (HasP10Instructions) {
         this->GemmFloatKernel = MlasSgemmKernelPOWER10;
