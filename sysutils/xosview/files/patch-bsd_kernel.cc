--- bsd/kernel.cc.orig	2018-09-12 13:52:23 UTC
+++ bsd/kernel.cc
@@ -93,6 +93,9 @@ static int mib_uvm[2] = { CTL_VM, VM_UVMEXP2 };
 static int mib_uvm[2] = { CTL_VM, VM_UVMEXP };
 #endif
 #else
+#if defined(XOSVIEW_FREEBSD)
+#define _WANT_VMMETER
+#endif
 #include <sys/vmmeter.h>
 #endif
 
@@ -339,7 +342,9 @@ BSDGetPageStats(uint64_t *meminfo, uint64_t *pageinfo)
 	GET_VM_STATS(v_active_count);
 	GET_VM_STATS(v_inactive_count);
 	GET_VM_STATS(v_wire_count);
+#if __FreeBSD_version < 1200017
 	GET_VM_STATS(v_cache_count);
+#endif
 	GET_VM_STATS(v_free_count);
 	GET_VM_STATS(v_page_size);
 	GET_VM_STATS(v_vnodepgsin);
@@ -361,7 +366,9 @@ BSDGetPageStats(uint64_t *meminfo, uint64_t *pageinfo)
 		meminfo[0] = (uint64_t)vm.v_active_count * vm.v_page_size;
 		meminfo[1] = (uint64_t)vm.v_inactive_count * vm.v_page_size;
 		meminfo[2] = (uint64_t)vm.v_wire_count * vm.v_page_size;
+#if __FreeBSD_version < 1200017
 		meminfo[3] = (uint64_t)vm.v_cache_count * vm.v_page_size;
+#endif
 		meminfo[4] = (uint64_t)vm.v_free_count * vm.v_page_size;
 #else  /* XOSVIEW_DFBSD */
 		meminfo[0] = (uint64_t)vms.v_active_count * vms.v_page_size;
