Fix memory display in the header on FreeBSD/powerpc

https://github.com/hishamhm/htop/pull/871

--- freebsd/FreeBSDProcessList.c.orig	2018-04-10 13:42:59 UTC
+++ freebsd/FreeBSDProcessList.c
@@ -296,31 +296,46 @@ static inline void FreeBSDProcessList_scanMemoryInfo(P
    //
    // htop_used   = active + (wired - arc)
    // htop_cache  = buffers + cache + arc
-   size_t len = sizeof(pl->totalMem);
+   u_long totalMem;
+   u_int memActive, memWire, cachedMem;
+   long buffersMem;
+   uint64_t memZfsArc;
+   size_t len;
 
    //disabled for now, as it is always smaller than phycal amount of memory...
    //...to avoid "where is my memory?" questions
    //sysctl(MIB_vm_stats_vm_v_page_count, 4, &(pl->totalMem), &len, NULL, 0);
    //pl->totalMem *= pageSizeKb;
-   sysctl(MIB_hw_physmem, 2, &(pl->totalMem), &len, NULL, 0);
-   pl->totalMem /= 1024;
+   len = sizeof(totalMem);
+   sysctl(MIB_hw_physmem, 2, &(totalMem), &len, NULL, 0);
+   totalMem /= 1024;
+   pl->totalMem = totalMem;
 
-   sysctl(MIB_vm_stats_vm_v_active_count, 4, &(fpl->memActive), &len, NULL, 0);
-   fpl->memActive *= pageSizeKb;
+   len = sizeof(memActive);
+   sysctl(MIB_vm_stats_vm_v_active_count, 4, &(memActive), &len, NULL, 0);
+   memActive *= pageSizeKb;
+   fpl->memActive = memActive;
 
-   sysctl(MIB_vm_stats_vm_v_wire_count, 4, &(fpl->memWire), &len, NULL, 0);
-   fpl->memWire *= pageSizeKb;
+   len = sizeof(memWire);
+   sysctl(MIB_vm_stats_vm_v_wire_count, 4, &(memWire), &len, NULL, 0);
+   memWire *= pageSizeKb;
+   fpl->memWire = memWire;
 
-   sysctl(MIB_vfs_bufspace, 2, &(pl->buffersMem), &len, NULL, 0);
-   pl->buffersMem /= 1024;
+   len = sizeof(buffersMem);
+   sysctl(MIB_vfs_bufspace, 2, &(buffersMem), &len, NULL, 0);
+   buffersMem /= 1024;
+   pl->buffersMem = buffersMem;
 
-   sysctl(MIB_vm_stats_vm_v_cache_count, 4, &(pl->cachedMem), &len, NULL, 0);
-   pl->cachedMem *= pageSizeKb;
+   len = sizeof(cachedMem);
+   sysctl(MIB_vm_stats_vm_v_cache_count, 4, &(cachedMem), &len, NULL, 0);
+   cachedMem *= pageSizeKb;
+   pl->cachedMem = cachedMem;
 
    if (fpl->zfsArcEnabled) {
-      len = sizeof(fpl->memZfsArc);
-      sysctl(MIB_kstat_zfs_misc_arcstats_size, 5, &(fpl->memZfsArc), &len , NULL, 0);
-      fpl->memZfsArc /= 1024;
+      len = sizeof(memZfsArc);
+      sysctl(MIB_kstat_zfs_misc_arcstats_size, 5, &(memZfsArc), &len , NULL, 0);
+      memZfsArc /= 1024;
+      fpl->memZfsArc = memZfsArc;
       fpl->memWire -= fpl->memZfsArc;
       pl->cachedMem += fpl->memZfsArc;
       // maybe when we learn how to make custom memory meter
