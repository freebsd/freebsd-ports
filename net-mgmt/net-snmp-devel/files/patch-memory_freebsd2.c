--- agent/mibgroup/ucd-snmp/memory_freebsd2.c	Sat Mar  3 19:40:34 2007
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	Sat Mar  3 19:39:57 2007
@@ -256,7 +256,7 @@
 
     u_long          phys_mem;
     size_t          phys_mem_size = sizeof(phys_mem);
-    int             phys_mem_mib[] = { CTL_HW, HW_USERMEM };
+    int             phys_mem_mib[] = { CTL_HW, HW_PHYSMEM };
 
 #ifdef BUFSPACE_SYMBOL
     long            bufspace;
