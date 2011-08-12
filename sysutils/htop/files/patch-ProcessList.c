--- ./ProcessList.c.orig	2010-11-26 18:50:25.000000000 +0200
+++ ./ProcessList.c	2011-08-11 13:07:08.000000000 +0300
@@ -32,6 +32,19 @@
 #include "debug.h"
 #include <assert.h>
 
+#ifndef PAGE_SIZE
+#define PAGE_SIZE sysconf(_SC_PAGESIZE)
+#endif
+
+#ifdef __FreeBSD__
+#define KB 1024
+#define SYSCTLBYNAME(name, var, len) sysctlbyname(name, &(var), &(len), NULL, 0)
+#include <kvm.h>
+#include <paths.h>
+#include <fcntl.h>
+#include <sys/sysctl.h>
+#endif
+
 /*{
 
 #ifndef PROCDIR
@@ -665,15 +678,24 @@
 
 void ProcessList_scan(ProcessList* this) {
    unsigned long long int usertime, nicetime, systemtime, systemalltime, idlealltime, idletime, totaltime, virtalltime;
+   #ifndef __FreeBSD__
    unsigned long long int swapFree = 0;
+   #endif
+   int cpus = this->cpuCount;
+   FILE* file = NULL;
 
-   FILE* file = fopen(PROCMEMINFOFILE, "r");
+   #ifdef __FreeBSD__
+   kvm_t *kd = NULL;
+   struct kvm_swap kvmswapinfo[1];
+   size_t len = 0;
+   #endif
+
+   #ifndef __FreeBSD__
+   file = fopen(PROCMEMINFOFILE, "r");
    assert(file != NULL);
-   int cpus = this->cpuCount;
    {
       char buffer[128];
       while (fgets(buffer, 128, file)) {
-   
          switch (buffer[0]) {
          case 'M':
             if (String_startsWith(buffer, "MemTotal:"))
@@ -700,10 +722,35 @@
          }
       }
    }
+   fclose(file);
+   #endif
 
+   #ifdef __FreeBSD__
+   len = sizeof(this->totalMem);
+   SYSCTLBYNAME("vm.stats.vm.v_page_count", this->totalMem, len);
+   this->totalMem *= PAGE_SIZE / KB;
+   len = sizeof(this->cachedMem);
+   SYSCTLBYNAME("vm.stats.vm.v_cache_count", this->cachedMem, len);
+   this->cachedMem *= PAGE_SIZE / KB;
+   len = sizeof(this->buffersMem);
+   SYSCTLBYNAME("vfs.bufspace", this->buffersMem, len);
+   this->buffersMem /= KB;
+   len = sizeof(this->usedMem);
+   SYSCTLBYNAME("vm.stats.vm.v_active_count", this->usedMem, len);
+   this->usedMem = this->usedMem * PAGE_SIZE / KB + this->cachedMem + this->buffersMem;
+   this->freeMem = this->totalMem - this->usedMem;
+   kd = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, NULL);
+   assert(kd != NULL);
+   kvm_getswapinfo(kd, kvmswapinfo, 1, 0);
+   this->totalSwap = kvmswapinfo[0].ksw_total * PAGE_SIZE / KB;
+   this->usedSwap = kvmswapinfo[0].ksw_used * PAGE_SIZE / KB;
+   kvm_close(kd);
+   #endif
+
+   #ifndef __FreeBSD__
    this->usedMem = this->totalMem - this->freeMem;
    this->usedSwap = this->totalSwap - swapFree;
-   fclose(file);
+   #endif
 
    file = fopen(PROCSTATFILE, "r");
    assert(file != NULL);
