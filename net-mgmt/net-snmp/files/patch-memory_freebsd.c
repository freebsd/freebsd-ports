--- agent/mibgroup/hardware/memory/memory_freebsd.c.orig	2008-05-28 20:48:46.000000000 +0900
+++ agent/mibgroup/hardware/memory/memory_freebsd.c	2008-11-14 16:56:48.000000000 +0900
@@ -59,6 +59,7 @@
     sysctlbyname("vfs.bufspace",    &bufspace,    &buf_size, NULL, 0);
     sysctlbyname("vfs.maxbufspace", &maxbufspace, &buf_size, NULL, 0);
     auto_nlist(SUM_SYMBOL,      (char *) &vmem,     sizeof(vmem));
+    auto_nlist(BUFSPACE_SYMBOL, (char *) &bufspace, sizeof(bufspace));
 #ifndef freebsd4
     pagesize = 1024;
 #else
@@ -75,7 +76,7 @@
         if (!mem->descr)
              mem->descr = strdup("Physical memory");
         mem->units = pagesize;
-        mem->size  = user_mem/pagesize;
+        mem->size  = phys_mem/pagesize;
         mem->free  = total.t_free;
     }
 
@@ -134,6 +135,17 @@
         mem->free  = vmem.v_cache_max - vmem.v_cache_count;
     }
 
+    mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_MBUF, 1 );
+    if (!mem) {
+        snmp_log_perror("No Memory Buffer info entry");
+    } else {
+        if (!mem->descr)
+            mem->descr = strdup("Memory Buffer");
+        mem->units = pagesize;
+        mem->size  = bufspace/pagesize;
+        mem->free  = -1;
+    }
+
     nswap = swapmode(pagesize);
     mem = netsnmp_memory_get_byIdx( NETSNMP_MEM_TYPE_SWAP, 1 );
     if (!mem) {
