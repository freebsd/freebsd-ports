--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	Sat Apr 20 16:30:08 2002
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	Wed Apr 24 01:49:01 2002
@@ -274,7 +274,7 @@
     size_t          total_size = sizeof(total);
     int             total_mib[] = { CTL_VM, VM_METER };
 
-    long            phys_mem;
+    u_long          phys_mem;
     size_t          phys_mem_size = sizeof(phys_mem);
     int             phys_mem_mib[] = { CTL_HW, HW_USERMEM };
 
