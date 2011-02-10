--- agent/mibgroup/hardware/memory/memory_freebsd.c.orig	2011-02-04 10:33:56.000000000 -0200
+++ agent/mibgroup/hardware/memory/memory_freebsd.c	2011-02-04 10:33:38.000000000 -0200
@@ -43,10 +43,17 @@
 
     u_long         phys_mem;
     u_long         user_mem;
+    unsigned int   cache_count;
+    unsigned int   cache_max;
     unsigned int   bufspace;
     unsigned int   maxbufspace;
+    unsigned int   inact_count;
+    unsigned int   page_count;
     size_t         mem_size  = sizeof(phys_mem);
+    size_t         cache_size = sizeof(cache_count);
     size_t         buf_size  = sizeof(bufspace);
+    size_t         inact_size = sizeof(inact_count);
+    size_t         page_size = sizeof(page_count);
     int            phys_mem_mib[] = { CTL_HW, HW_PHYSMEM };
     int            user_mem_mib[] = { CTL_HW, HW_USERMEM };
 
@@ -56,15 +63,20 @@
     sysctl(total_mib,    2, &total,    &total_size,    NULL, 0);
     sysctl(phys_mem_mib, 2, &phys_mem, &mem_size,      NULL, 0);
     sysctl(user_mem_mib, 2, &user_mem, &mem_size,      NULL, 0);
+    sysctlbyname("vm.stats.vm.v_cache_count", &cache_count, &cache_size, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_cache_max", &cache_max, &cache_size, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_inactive_count", &inact_count, &inact_size, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_page_count", &page_count, &page_size, NULL, 0);
     sysctlbyname("vfs.bufspace",    &bufspace,    &buf_size, NULL, 0);
     sysctlbyname("vfs.maxbufspace", &maxbufspace, &buf_size, NULL, 0);
-    auto_nlist(SUM_SYMBOL,      (char *) &vmem,     sizeof(vmem));
 #ifndef freebsd4
     pagesize = 1024;
 #else
     pagesize = getpagesize();
 #endif
 
+    nswap = swapmode(pagesize);    
+
     /*
      * ... and save this in a standard form.
      */
@@ -75,7 +87,7 @@
         if (!mem->descr)
              mem->descr = strdup("Physical memory");
         mem->units = pagesize;
-        mem->size  = user_mem/pagesize;
+        mem->size  = page_count;
         mem->free  = total.t_free;
     }
 
@@ -87,7 +99,7 @@
              mem->descr = strdup("Real memory");
         mem->units = pagesize;
         mem->size  = total.t_rm;
-        mem->free  = total.t_arm;
+        mem->free  = total.t_rm - total.t_arm;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_VIRTMEM, 1 );
@@ -97,8 +109,8 @@
         if (!mem->descr)
              mem->descr = strdup("Virtual memory");
         mem->units = pagesize;
-        mem->size  = total.t_vm;
-        mem->free  = total.t_avm;
+	mem->size = page_count + swapTotal;
+	mem->free = total.t_free + swapFree;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SHARED, 1 );
@@ -109,7 +121,7 @@
              mem->descr = strdup("Shared virtual memory");
         mem->units = pagesize;
         mem->size  = total.t_vmshr;
-        mem->free  = total.t_avmshr;
+	mem->free  = total.t_vmshr - total.t_avmshr;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SHARED2, 1 );
@@ -120,7 +132,7 @@
              mem->descr = strdup("Shared real memory");
         mem->units = pagesize;
         mem->size  = total.t_rmshr;
-        mem->free  = total.t_armshr;
+        mem->free  = total.t_rmshr - total.t_armshr;
     }
 
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_CACHED, 1 );
@@ -129,12 +141,11 @@
     } else {
         if (!mem->descr)
              mem->descr = strdup("Cached memory");
-        mem->units = vmem.v_page_size;
-        mem->size  = vmem.v_cache_max;
-        mem->free  = vmem.v_cache_max - vmem.v_cache_count;
+	mem->units = pagesize;
+	mem->size  = cache_count + inact_count;
+	mem->free  = cache_max - cache_count;
     }
 
-    nswap = swapmode(pagesize);
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SWAP, 1 );
     if (!mem) {
         snmp_log_perror("No Swap info entry");
@@ -201,6 +212,9 @@
 /*
  * swapmode is based on a program called swapinfo written
  * by Kevin Lahey <kml@rokkaku.atl.ga.us>.
+ * 
+ * sync'd with swapmode_sysctl(), etc. from /usr/src/usr.sbin/pstat/pstat.c
+ * as of FreeBSD 8.1
  */
 
 #include <sys/conf.h>
@@ -208,51 +222,30 @@
 int
 swapmode(long pagesize)
 {
-    int             i, n;
-    static kvm_t   *kd = NULL;
-    struct kvm_swap kswap[16];
-    netsnmp_memory_info *mem;
-    char buf[1024];
-
-    if (kd == NULL)
-        kd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, NULL);
-    n = kvm_getswapinfo(kd, kswap, sizeof(kswap) / sizeof(kswap[0]), 0);
-
-    swapUsed = swapTotal = swapFree = 0;
-
-    if ( n > 1 ) {
-        /*
-         * If there are multiple swap devices, then record
-         *   the statistics for each one separately...
-         */
-        for (i = 0; i < n; ++i) {
-            mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SWAP+1+i, 1 );
-            if (!mem)
-                continue;
-            if (!mem->descr) {
-                sprintf(buf, "swap %s", kswap[i].ksw_devname);
-                mem->descr = strdup( buf );
-            }
-            mem->units = pagesize;
-            mem->size  = kswap[i].ksw_total;
-            mem->free  = kswap[i].ksw_total - kswap[i].ksw_used;
-            /*
-             *  ... and keep a running total for the overall swap stats
-             */
-            swapTotal += kswap[i].ksw_total;
-            swapUsed  += kswap[i].ksw_used;
+	struct kvm_swap ksw;
+	struct xswdev xsw;
+	size_t mibsize, size;
+	int mib[16], n;
+	
+	swapUsed = swapTotal = swapFree = 0;
+	
+	mibsize = sizeof mib / sizeof mib[0];
+	if (sysctlnametomib("vm.swap_info", mib, &mibsize) == -1)
+	err(1, "sysctlnametomib()");
+	for (n = 0; ; ++n) {
+	mib[mibsize] = n;
+	size = sizeof xsw;
+	if (sysctl(mib, mibsize + 1, &xsw, &size, NULL, 0) == -1)
+	break;
+	ksw.ksw_used = xsw.xsw_used;
+	ksw.ksw_total = xsw.xsw_nblks;
+	ksw.ksw_flags = xsw.xsw_flags;
+	
+	swapTotal += ksw.ksw_total;
+	swapUsed += ksw.ksw_used;
         }
-    } else {
-        /*
-         * If there's only one swap device, then don't bother
-         *   with individual statistics.
-         */
-        swapTotal += kswap[0].ksw_total;
-        swapUsed  += kswap[0].ksw_used;
-    }
-
-    swapFree = swapTotal - swapUsed;
-    return n;
+	swapFree = swapTotal - swapUsed;
+	return n;
 }
 #endif
 
