--- read_mem.c.orig	2007-04-12 20:38:40 UTC
+++ read_mem.c
@@ -56,6 +56,8 @@ char buf[BUFFER_LENGTH];
 // Machine dependent headers
 // FreeBSD
 #if defined(__FreeBSD__)
+#define _WANT_VMMETER
+#include <sys/param.h>
 #include <sys/conf.h>
 #include <osreldate.h>
 #include <kvm.h>
@@ -336,6 +338,14 @@ void error_handle( int place, const char * message )
 int read_meminfo() {
       int pagesize, pageshift;
 #if __FreeBSD_version > 400000
+	
+      /* setup pageshift */
+      pagesize = getpagesize();
+      pageshift = 0;
+      while (pagesize > 1) {
+             pageshift++;
+             pagesize >>= 1;
+      }
 
       struct kvm_swap kswap[SWAP_DEVICES];
       int i, swaps;
@@ -347,10 +357,6 @@ int read_meminfo() {
       time_t current_time;
       #define GETSWAP_DELAY 60 /* 1 min */
 
-      /* get the info */
-      if (kvm_read(kd, cnt_offset, (int *)(&sum), sizeof(sum)) != sizeof(sum))
-            return (-1); 
-            
       /* we obtain swap info every GETSWAP_DELAY seconds because of
        * kvm_getswapinfo CPU load 
        */
@@ -406,9 +412,19 @@ int read_meminfo() {
 
 #endif /* if __FreeBSD_version > 400000  */
 
-      state.fresh.total =  pagetok(sum.v_page_count);
-      state.fresh.used = pagetok(sum.v_page_count-sum.v_free_count);
-      state.fresh.free = pagetok(sum.v_free_count);
+      unsigned long physmem, freemem, inacmem;
+      size_t sz = sizeof(unsigned long);
+
+      physmem = 0;
+      freemem = 0;
+      inacmem = 0;
+      sysctlbyname("hw.physmem", &physmem, &sz, NULL, 0); 
+      sysctlbyname("vm.stats.vm.v_free_count", &freemem, &sz, NULL, 0); 
+      sysctlbyname("vm.stats.vm.v_inactive_count", &inacmem, &sz, NULL, 0);
+
+      state.fresh.total = physmem;
+      state.fresh.free = pagetok(freemem + inacmem);
+      state.fresh.used = physmem - pagetok(freemem + inacmem);
                         
       state.fresh.shared = 0;  /* dont know how to get these */
       state.fresh.buffers = 0;
