--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	Sun Sep 16 17:16:16 2001
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	Fri Mar 28 13:18:19 2003
@@ -9,7 +9,9 @@
 #include <sys/param.h>
 #include <sys/time.h>
 #include <sys/proc.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#endif
 #ifdef freebsd5
 #include <sys/bio.h>
 #endif
@@ -232,7 +234,7 @@
     size_t total_size = sizeof (total);
     int total_mib[] = { CTL_VM, VM_METER };
 
-    long phys_mem;
+    u_long phys_mem;
     size_t phys_mem_size = sizeof(phys_mem);
     int phys_mem_mib[] = { CTL_HW, HW_USERMEM };
 
