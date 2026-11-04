--- third_party/cpuinfo/src/init.c.orig	2026-11-04 16:29:16 UTC
+++ third_party/cpuinfo/src/init.c
@@ -38,6 +38,8 @@ bool CPUINFO_ABI cpuinfo_initialize(void) {
 	pthread_once(&init_guard, &cpuinfo_arm_linux_init);
 #elif defined(__MACH__) && defined(__APPLE__)
 	pthread_once(&init_guard, &cpuinfo_arm_mach_init);
+#elif defined(__FreeBSD__)
+	pthread_once(&init_guard, &cpuinfo_arm_freebsd_init);
 #elif defined(_WIN32)
 	InitOnceExecuteOnce(&init_guard, &cpuinfo_arm_windows_init, NULL, NULL);
 #else
