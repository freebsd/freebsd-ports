-- Dispatch cpuinfo_initialize() to the new cpuinfo_arm_freebsd_init() on
-- FreeBSD/aarch64, mirroring the existing __FreeBSD__ dispatch already
-- present for x86. Without this, cpuinfo_initialize() silently does nothing
-- on FreeBSD/aarch64 and libtorch_cpu.so fails to load with "Undefined
-- symbol \"cpuinfo_isa\"".

-- Upstreamed: https://github.com/pytorch/cpuinfo/pull/436

--- cpuinfo-with-freebsd-support/src/init.c.orig	2026-09-21 07:02:31 UTC
+++ cpuinfo-with-freebsd-support/src/init.c
@@ -38,6 +38,8 @@ bool CPUINFO_ABI cpuinfo_initialize(void) {
 	pthread_once(&init_guard, &cpuinfo_arm_linux_init);
 #elif defined(__MACH__) && defined(__APPLE__)
 	pthread_once(&init_guard, &cpuinfo_arm_mach_init);
+#elif defined(__FreeBSD__)
+	pthread_once(&init_guard, &cpuinfo_arm_freebsd_init);
 #elif defined(_WIN32)
 	InitOnceExecuteOnce(&init_guard, &cpuinfo_arm_windows_init, NULL, NULL);
 #else
