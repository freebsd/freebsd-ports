--- ProcessList.c.orig	2012-02-03 01:45:11.000000000 +0200
+++ ProcessList.c	2012-05-16 17:39:50.000000000 +0300
@@ -25,6 +25,19 @@
 #include <time.h>
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
 #include "Vector.h"
 #include "Hashtable.h"
@@ -749,11 +762,13 @@
 
 void ProcessList_scan(ProcessList* this) {
    unsigned long long int usertime, nicetime, systemtime, systemalltime, idlealltime, idletime, totaltime, virtalltime;
-   unsigned long long int swapFree = 0;
+   int cpus = this->cpuCount;
+   FILE* file = NULL;
 
-   FILE* file = fopen(PROCMEMINFOFILE, "r");
+   #ifndef __FreeBSD__
+   unsigned long long int swapFree = 0;
+   file = fopen(PROCMEMINFOFILE, "r");
    assert(file != NULL);
-   int cpus = this->cpuCount;
    {
       char buffer[128];
       while (fgets(buffer, 128, file)) {
@@ -788,6 +803,33 @@
    this->usedMem = this->totalMem - this->freeMem;
    this->usedSwap = this->totalSwap - swapFree;
    fclose(file);
+   #endif
+
+   #ifdef __FreeBSD__
+   kvm_t *kd = NULL;
+   struct kvm_swap kvmswapinfo[1];
+   size_t len = 0;
+
+   kd = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, NULL);
+   assert(kd != NULL);
+   kvm_getswapinfo(kd, kvmswapinfo, 1, 0);
+   this->totalSwap = kvmswapinfo[0].ksw_total * PAGE_SIZE / KB;
+   this->usedSwap = kvmswapinfo[0].ksw_used * PAGE_SIZE / KB;
+   kvm_close(kd);
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
+   #endif
 
    file = fopen(PROCSTATFILE, "r");
    assert(file != NULL);
