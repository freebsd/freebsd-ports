--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	Sat Nov  9 15:59:53 2002
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	Sat Feb 21 11:55:05 2004
@@ -204,6 +204,7 @@
     if (kd == NULL)
         kd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, NULL);
 
+#if !defined(freebsd5)
     auto_nlist(NSWDEV_SYMBOL, (char *) &nswdev, sizeof(nswdev));
     auto_nlist(DMMAX_SYMBOL, (char *) &dmmax, sizeof(dmmax));
 
@@ -212,6 +213,7 @@
         return;
 
     auto_nlist(SWDEVT_SYMBOL, (char *) sw, nswdev * sizeof(*sw));
+#endif
 
     n = kvm_getswapinfo(kd, kswap, sizeof(kswap) / sizeof(kswap[0]), 0);
 
@@ -242,7 +244,9 @@
     swapUsed *= pagesize;
     swapFree *= pagesize;
 
+#if !defined(freebsd5)
     free(sw);
+#endif
 }
 #endif
 
@@ -274,7 +278,7 @@
     size_t          total_size = sizeof(total);
     int             total_mib[] = { CTL_VM, VM_METER };
 
-    long            phys_mem;
+    u_long          phys_mem;
     size_t          phys_mem_size = sizeof(phys_mem);
     int             phys_mem_mib[] = { CTL_HW, HW_USERMEM };
 
