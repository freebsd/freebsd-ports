--- agent/mibgroup/hardware/memory/memory_freebsd.c.orig	2010-06-29 12:34:48.000000000 +0200
+++ agent/mibgroup/hardware/memory/memory_freebsd.c	2010-07-01 13:32:34.000000000 +0200
@@ -43,10 +43,15 @@
 
     u_long         phys_mem;
     u_long         user_mem;
+    unsigned int   cache_count;
+    unsigned int   cache_max;
     unsigned int   bufspace;
     unsigned int   maxbufspace;
+    unsigned int   inact_count;
     size_t         mem_size  = sizeof(phys_mem);
+    size_t         cache_size  = sizeof(cache_count);
     size_t         buf_size  = sizeof(bufspace);
+    size_t         inact_size  = sizeof(inact_count);
     int            phys_mem_mib[] = { CTL_HW, HW_PHYSMEM };
     int            user_mem_mib[] = { CTL_HW, HW_USERMEM };
 
@@ -56,9 +61,11 @@
     sysctl(total_mib,    2, &total,    &total_size,    NULL, 0);
     sysctl(phys_mem_mib, 2, &phys_mem, &mem_size,      NULL, 0);
     sysctl(user_mem_mib, 2, &user_mem, &mem_size,      NULL, 0);
+    sysctlbyname("vm.stats.vm.v_cache_count",    &cache_count,    &cache_size, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_cache_max",    &cache_max,    &cache_size, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_inactive_count",    &inact_count,    &inact_size, NULL, 0);
     sysctlbyname("vfs.bufspace",    &bufspace,    &buf_size, NULL, 0);
     sysctlbyname("vfs.maxbufspace", &maxbufspace, &buf_size, NULL, 0);
-    auto_nlist(SUM_SYMBOL,      (char *) &vmem,     sizeof(vmem));
 #ifndef freebsd4
     pagesize = 1024;
 #else
@@ -75,7 +82,7 @@
         if (!mem->descr)
              mem->descr = strdup("Physical memory");
         mem->units = pagesize;
-        mem->size  = user_mem/pagesize;
+        mem->size  = phys_mem/pagesize;
         mem->free  = total.t_free;
     }
 
@@ -129,9 +136,9 @@
     } else {
         if (!mem->descr)
              mem->descr = strdup("Cached memory");
-        mem->units = vmem.v_page_size;
-        mem->size  = vmem.v_cache_max;
-        mem->free  = vmem.v_cache_max - vmem.v_cache_count;
+        mem->units = pagesize;
+        mem->size  = cache_max + inact_count;
+        mem->free  = cache_max - cache_count;
     }
 
     nswap = swapmode(pagesize);
