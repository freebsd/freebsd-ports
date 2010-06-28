--- agent/mibgroup/hardware/memory/memory_freebsd.c.orig 2008-05-28 14:48:46.000000000 +0300
+++ agent/mibgroup/hardware/memory/memory_freebsd.c      2010-06-27 15:19:27.000000000 +0300
@@ -43,9 +43,12 @@
 
     u_long         phys_mem;
     u_long         user_mem;
+    unsigned int   cache_count;
+    unsigned int   cache_max;
     unsigned int   bufspace;
     unsigned int   maxbufspace;
     size_t         mem_size  = sizeof(phys_mem);
+    size_t         cache_size  = sizeof(cache_count);
     size_t         buf_size  = sizeof(bufspace);
     int            phys_mem_mib[] = { CTL_HW, HW_PHYSMEM };
     int            user_mem_mib[] = { CTL_HW, HW_USERMEM };
@@ -56,9 +59,10 @@
     sysctl(total_mib,    2, &total,    &total_size,    NULL, 0);
     sysctl(phys_mem_mib, 2, &phys_mem, &mem_size,      NULL, 0);
     sysctl(user_mem_mib, 2, &user_mem, &mem_size,      NULL, 0);
+    sysctlbyname("vm.stats.vm.v_cache_count",    &cache_count,    &cache_size, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_cache_max",    &cache_max,    &cache_size, NULL, 0);
     sysctlbyname("vfs.bufspace",    &bufspace,    &buf_size, NULL, 0);
     sysctlbyname("vfs.maxbufspace", &maxbufspace, &buf_size, NULL, 0);
-    auto_nlist(SUM_SYMBOL,      (char *) &vmem,     sizeof(vmem));
 #ifndef freebsd4
     pagesize = 1024;
 #else
@@ -75,7 +79,7 @@
         if (!mem->descr)
              mem->descr = strdup("Physical memory");
         mem->units = pagesize;
-        mem->size  = user_mem/pagesize;
+        mem->size  = phys_mem/pagesize;
         mem->free  = total.t_free;
     }
 
@@ -129,9 +133,9 @@
     } else {
         if (!mem->descr)
              mem->descr = strdup("Cached memory");
-        mem->units = vmem.v_page_size;
-        mem->size  = vmem.v_cache_max;
-        mem->free  = vmem.v_cache_max - vmem.v_cache_count;
+        mem->units = pagesize;
+        mem->size  = cache_max;
+        mem->free  = cache_max - cache_count;
     }
 
     nswap = swapmode(pagesize);
