--- third_party/cpuinfo/src/cpuinfo/internal-api.h.orig	2026-11-04 16:29:16 UTC
+++ third_party/cpuinfo/src/cpuinfo/internal-api.h
@@ -59,6 +59,7 @@ CPUINFO_PRIVATE void cpuinfo_arm_linux_init(void);
 #endif
 CPUINFO_PRIVATE void cpuinfo_arm_mach_init(void);
 CPUINFO_PRIVATE void cpuinfo_arm_linux_init(void);
+CPUINFO_PRIVATE void cpuinfo_arm_freebsd_init(void);
 CPUINFO_PRIVATE void cpuinfo_riscv_linux_init(void);
 CPUINFO_PRIVATE void cpuinfo_emscripten_init(void);
 
