--- src/sysinfo_freebsd.c.orig	2026-02-19 17:57:59 UTC
+++ src/sysinfo_freebsd.c
@@ -5,10 +5,12 @@
 #include <libgeom.h>
 #include <libutil.h>
 #include <machine/param.h>
+#include <paths.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/fcntl.h>
 #include <sys/filedesc.h>
 #include <sys/linker.h>
 #include <sys/mount.h>
@@ -60,6 +62,25 @@ int sys_cpu_info(struct cpu_info_t *cur_cpu_info) {
   return 0;
 }
 
+static uint64_t round1024(uint64_t val) {
+  return (val + 512) >> 10;
+}
+
+static void sys_mem_info_print(char* name, uint64_t val, int pagesize, int isPages) {
+  uint64_t GiB, MiB, KiB, Bytes, Pages;
+  if (isPages) {
+    Pages = val;
+    Bytes = Pages * pagesize;
+  } else {
+    Bytes = val;
+    Pages = (pagesize <= 0 ? 0 : Bytes / pagesize);
+  }
+  KiB = round1024(Bytes);
+  MiB = round1024(KiB);
+  GiB = round1024(MiB);
+  println("%s|%5llu|%8llu|%11llu|%14llu|%11llu\n", name, GiB, MiB, KiB, Bytes, Pages);
+}
+
 // stole it from top
 #define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
 static void getsysctl(const char *name, void *ptr, size_t len) {
@@ -67,42 +88,54 @@ static void getsysctl(const char *name, void *ptr, siz
 
   sysctlbyname(name, ptr, &nlen, NULL, 0);
 }
-static int pageshift;
-#define pagetok(size) ((size) << pageshift)
 
 void sys_mem_info(void) {
 
-  uint64_t physmem;
-  int pagesize, v_free, v_active, v_inactive, v_cache, swap_total, swap_used;
+  uint64_t realmem, physmem, v_bufspace, swap_total_sysctl, swap_total = 0, swap_used = 0;
+  unsigned int pagesize, v_free, v_active, v_inactive, v_laundry, v_wire;
+  struct kvm_swap swapary[1];
+  static kvm_t *kd = NULL;
+  int n;
 
-  GETSYSCTL("hw.pagesize", pagesize);
-
-  pageshift = 0;
-  int ps = pagesize;
-  while (ps > 1) {
-    pageshift++;
-    ps >>= 1;
+  if (kd == NULL) {
+    kd = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, "kvm_open");
   }
-  pageshift -= 10; // LOG1024
+  if (kd != NULL) {
+    n = kvm_getswapinfo(kd, swapary, 1, 0);
+    if (n >= 0 && swapary[0].ksw_total != 0) {
+      swap_total = swapary[0].ksw_total;
+      swap_used = swapary[0].ksw_used;
+    }
+  }
 
+  GETSYSCTL("hw.pagesize", pagesize);
   GETSYSCTL("vm.stats.vm.v_free_count", v_free);
   GETSYSCTL("vm.stats.vm.v_active_count", v_active);
   GETSYSCTL("vm.stats.vm.v_inactive_count", v_inactive);
-  GETSYSCTL("vm.stats.vm.v_cache_count", v_cache);
-  GETSYSCTL("vm.swap_total", swap_total);
-  GETSYSCTL("vm.swap_reserved", swap_used);
+  GETSYSCTL("vm.stats.vm.v_laundry_count", v_laundry);
+  GETSYSCTL("vm.stats.vm.v_wire_count", v_wire);
+  GETSYSCTL("vfs.bufspace", v_bufspace);
+  GETSYSCTL("vm.swap_total", swap_total_sysctl);
+  GETSYSCTL("hw.realmem", realmem);
   GETSYSCTL("hw.physmem", physmem);
 
-  println("MemTotal: %llu kB\n", physmem / 1024);
-  println("MemFree: %llu kB\n", pagetok(v_free));
-  println("MemAvailable: %llu kB\n",
-          (uint64_t)(v_free + v_inactive + v_cache) * pagesize / 1024);
-  println("Active: %llu kB\n", (uint64_t)v_active * pagesize / 1024);
-  println("Inactive: %llu kB\n", (uint64_t)v_inactive * pagesize / 1024);
-  println("Cached: %llu kB\n", (uint64_t)v_cache * pagesize / 1024);
-  println("SwapTotal: %llu kB\n", (uint64_t)swap_total / 1024);
-  println("SwapUsed: %llu kB\n", (uint64_t)swap_used / 1024);
-  println("SwapFree: %llu kB\n", (uint64_t)(swap_total - swap_used) / 1024);
+  pagesize = (pagesize <= 0 ? 1 : pagesize);
+
+  println("PageSize: %u Bytes\n", pagesize);
+  println(           "Name          | GiB |   MiB  |    KiB    |     Bytes    |   Pages\n");
+  sys_mem_info_print("RealMemTotal  ", realmem,                pagesize, 0);
+  sys_mem_info_print("PhysMemTotal  ", physmem,                pagesize, 0);
+  sys_mem_info_print("MemFree       ", v_free,                 pagesize, 1);
+  sys_mem_info_print("MemAvailable  ", v_free + v_inactive + v_laundry + v_bufspace / pagesize, pagesize, 1);
+  sys_mem_info_print("Active        ", v_active,               pagesize, 1);
+  sys_mem_info_print("Inactive      ", v_inactive,             pagesize, 1);
+  sys_mem_info_print("Laundry       ", v_laundry,              pagesize, 1);
+  sys_mem_info_print("Wired         ", v_wire,                 pagesize, 1);
+  sys_mem_info_print("Buffers       ", v_bufspace,             pagesize, 0);
+  sys_mem_info_print("SwapTotal Real", swap_total_sysctl,      pagesize, 0);
+  sys_mem_info_print("SwapTotal Phys", swap_total,             pagesize, 1);
+  sys_mem_info_print("SwapUsed      ", swap_used,              pagesize, 1);
+  sys_mem_info_print("SwapFree      ", swap_total - swap_used, pagesize, 1);
 }
 
 long long sys_open_files() {
