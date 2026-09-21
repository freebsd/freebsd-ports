-- Declare cpuinfo_arm_freebsd_init(), the new FreeBSD/aarch64 backend entry
-- point, alongside the other per-OS/arch init functions.
-- Needed so src/init.c can dispatch to it on FreeBSD/aarch64; see
-- src/arm/freebsd/init.c for why this backend is required.

-- Upstreamed: https://github.com/pytorch/cpuinfo/pull/436

--- cpuinfo-with-freebsd-support/src/cpuinfo/internal-api.h.orig	2026-09-21 07:02:31 UTC
+++ cpuinfo-with-freebsd-support/src/cpuinfo/internal-api.h
@@ -59,6 +59,7 @@ CPUINFO_PRIVATE void cpuinfo_arm_linux_init(void);
 #endif
 CPUINFO_PRIVATE void cpuinfo_arm_mach_init(void);
 CPUINFO_PRIVATE void cpuinfo_arm_linux_init(void);
+CPUINFO_PRIVATE void cpuinfo_arm_freebsd_init(void);
 CPUINFO_PRIVATE void cpuinfo_riscv_linux_init(void);
 CPUINFO_PRIVATE void cpuinfo_emscripten_init(void);
 
