--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	Sat Nov  9 23:59:53 2002
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	Sat Aug 16 17:09:01 2003
@@ -207,11 +207,13 @@
     auto_nlist(NSWDEV_SYMBOL, (char *) &nswdev, sizeof(nswdev));
     auto_nlist(DMMAX_SYMBOL, (char *) &dmmax, sizeof(dmmax));
 
+#if !defined(freebsd5)
     sw = (struct swdevt *) malloc(nswdev * sizeof(*sw));
     if (sw == NULL)
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
 
