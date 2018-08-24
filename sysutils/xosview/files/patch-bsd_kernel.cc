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
 
@@ -320,7 +323,22 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 		pageinfo[1] = (uint64_t)uvm.pgswapout;
 	}
 #else  /* HAVE_UVM */
-	struct vmmeter vm;
+	/*
+	 * Temporal patch from:
+	 * https://github.com/hills/xosview/commit/0b4861c9fed2dc8450edf2dff7988ebd784a520b.patch
+	 */
+	struct vmmeter_fbsd {
+		u_int v_active_count;
+		u_int v_inactive_count;
+		u_int v_wire_count;
+		u_int v_cache_count;
+		u_int v_free_count;
+		u_int v_page_size;
+		u_int v_vnodepgsin;
+		u_int v_vnodepgsout;
+		u_int v_swappgsin;
+		u_int v_swappgsout;
+	} vm;
 #if defined(XOSVIEW_FREEBSD)
 	size_t size = sizeof(unsigned int);
 #define	GET_VM_STATS(name) \
@@ -328,7 +346,9 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 	GET_VM_STATS(v_active_count);
 	GET_VM_STATS(v_inactive_count);
 	GET_VM_STATS(v_wire_count);
+#if __FreeBSD_version < 1200017
 	GET_VM_STATS(v_cache_count);
+#endif
 	GET_VM_STATS(v_free_count);
 	GET_VM_STATS(v_page_size);
 	GET_VM_STATS(v_vnodepgsin);
@@ -350,7 +370,9 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 		meminfo[0] = (uint64_t)vm.v_active_count * vm.v_page_size;
 		meminfo[1] = (uint64_t)vm.v_inactive_count * vm.v_page_size;
 		meminfo[2] = (uint64_t)vm.v_wire_count * vm.v_page_size;
+#if __FreeBSD_version < 1200017
 		meminfo[3] = (uint64_t)vm.v_cache_count * vm.v_page_size;
+#endif
 		meminfo[4] = (uint64_t)vm.v_free_count * vm.v_page_size;
 #else  /* XOSVIEW_DFBSD */
 		meminfo[0] = (uint64_t)vms.v_active_count * vms.v_page_size;
@@ -654,7 +676,7 @@ DevStat_Init(void) {
 
 uint64_t
 DevStat_Get(uint64_t *read_bytes, uint64_t *write_bytes) {
-	register int dn;
+	int dn;
 	long double busy_seconds;
 	uint64_t reads, writes, total_bytes = 0;
 	struct devinfo *tmp_dinfo;
