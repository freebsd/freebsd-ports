--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	Mon Sep 17 06:16:16 2001
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	Mon Mar  4 10:00:56 2002
@@ -232,7 +232,7 @@
     size_t total_size = sizeof (total);
     int total_mib[] = { CTL_VM, VM_METER };
 
-    long phys_mem;
+    u_long phys_mem;
     size_t phys_mem_size = sizeof(phys_mem);
     int phys_mem_mib[] = { CTL_HW, HW_USERMEM };
 
