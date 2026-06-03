--- src/utils/os_divers.c.orig	2026-01-10 11:14:36 UTC
+++ src/utils/os_divers.c
@@ -2301,6 +2301,9 @@ Bool gf_sys_get_rti_os(u32 refresh_time_ms, GF_SystemR
 	the_rti.physical_memory = EM_ASM_INT(return HEAP8.length);
 	s_mallinfo mi = mallinfo();
 	the_rti.physical_memory_avail = the_rti.physical_memory - (unsigned int)sbrk(0) + mi.fordblks;
+#elif defined(GPAC_CONFIG_FREEBSD)
+	/* FreeBSD doesn't have /proc/meminfo, would need sysctl to get memory info */
+	the_rti.physical_memory = the_rti.physical_memory_avail = 0;
 #else
 	the_rti.physical_memory = the_rti.physical_memory_avail = 0;
 	f = gf_fopen("/proc/meminfo", "r");
