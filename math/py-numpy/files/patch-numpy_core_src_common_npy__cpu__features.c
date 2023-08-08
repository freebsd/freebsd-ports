--- numpy/core/src/common/npy_cpu_features.c.orig	2023-06-18 00:19:04 UTC
+++ numpy/core/src/common/npy_cpu_features.c
@@ -570,6 +570,18 @@ npy__cpu_init_features(void)
     #ifndef PPC_FEATURE2_ARCH_3_1
         #define PPC_FEATURE2_ARCH_3_1  0x00040000
     #endif
+#elif defined(__FreeBSD__)
+    #include <machine/cpu.h>
+    #include <sys/auxv.h>
+    #ifndef PPC_FEATURE2_ARCH_2_07
+        #define PPC_FEATURE2_ARCH_2_07 0x80000000
+    #endif
+    #ifndef PPC_FEATURE2_ARCH_3_00
+        #define PPC_FEATURE2_ARCH_3_00 0x00800000
+    #endif
+    #ifndef PPC_FEATURE2_ARCH_3_1
+        #define PPC_FEATURE2_ARCH_3_1  0x00040000
+    #endif
 #endif
 
 static void
@@ -591,6 +603,25 @@ npy__cpu_init_features(void)
 
     elf_aux_info(AT_HWCAP2, &hwcap, sizeof(hwcap));
 #endif // __linux__
+    if (hwcap & PPC_FEATURE2_ARCH_3_1)
+    {
+        npy__cpu_have[NPY_CPU_FEATURE_VSX]  =
+        npy__cpu_have[NPY_CPU_FEATURE_VSX2] =
+        npy__cpu_have[NPY_CPU_FEATURE_VSX3] =
+        npy__cpu_have[NPY_CPU_FEATURE_VSX4] = 1;
+        return;
+    }
+    npy__cpu_have[NPY_CPU_FEATURE_VSX]  = 1;
+    npy__cpu_have[NPY_CPU_FEATURE_VSX2] = (hwcap & PPC_FEATURE2_ARCH_2_07) != 0;
+    npy__cpu_have[NPY_CPU_FEATURE_VSX3] = (hwcap & PPC_FEATURE2_ARCH_3_00) != 0;
+    npy__cpu_have[NPY_CPU_FEATURE_VSX4] = (hwcap & PPC_FEATURE2_ARCH_3_1) != 0;
+#elif defined(__FreeBSD__)
+    unsigned long hwcap;
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+    if ((hwcap & PPC_FEATURE_HAS_VSX) == 0)
+        return;
+
+    elf_aux_info(AT_HWCAP2, &hwcap, sizeof(hwcap));
     if (hwcap & PPC_FEATURE2_ARCH_3_1)
     {
         npy__cpu_have[NPY_CPU_FEATURE_VSX]  =
