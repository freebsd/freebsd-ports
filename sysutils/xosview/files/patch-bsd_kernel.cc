--- bsd/kernel.cc.orig	2017-11-04 15:05:59 UTC
+++ bsd/kernel.cc
@@ -93,6 +93,9 @@ static int mib_uvm[2] = { CTL_VM, VM_UVM
 static int mib_uvm[2] = { CTL_VM, VM_UVMEXP };
 #endif
 #else
+#if defined(XOSVIEW_FREEBSD)
+#define _WANT_VMMETER
+#endif
 #include <sys/vmmeter.h>
 #endif
 
@@ -328,7 +331,9 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 	GET_VM_STATS(v_active_count);
 	GET_VM_STATS(v_inactive_count);
 	GET_VM_STATS(v_wire_count);
+#if __FreeBSD_version < 1200017
 	GET_VM_STATS(v_cache_count);
+#endif
 	GET_VM_STATS(v_free_count);
 	GET_VM_STATS(v_page_size);
 	GET_VM_STATS(v_vnodepgsin);
@@ -350,7 +355,9 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 		meminfo[0] = (uint64_t)vm.v_active_count * vm.v_page_size;
 		meminfo[1] = (uint64_t)vm.v_inactive_count * vm.v_page_size;
 		meminfo[2] = (uint64_t)vm.v_wire_count * vm.v_page_size;
+#if __FreeBSD_version < 1200017
 		meminfo[3] = (uint64_t)vm.v_cache_count * vm.v_page_size;
+#endif
 		meminfo[4] = (uint64_t)vm.v_free_count * vm.v_page_size;
 #else  /* XOSVIEW_DFBSD */
 		meminfo[0] = (uint64_t)vms.v_active_count * vms.v_page_size;
@@ -654,7 +661,7 @@ DevStat_Init(void) {
 
 uint64_t
 DevStat_Get(uint64_t *read_bytes, uint64_t *write_bytes) {
-	register int dn;
+	int dn;
 	long double busy_seconds;
 	uint64_t reads, writes, total_bytes = 0;
 	struct devinfo *tmp_dinfo;
