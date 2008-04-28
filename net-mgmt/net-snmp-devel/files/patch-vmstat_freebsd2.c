--- agent/mibgroup/ucd-snmp/vmstat_freebsd2.c.orig	2008-04-25 16:28:53.000000000 +0300
+++ agent/mibgroup/ucd-snmp/vmstat_freebsd2.c	2008-04-25 16:29:01.000000000 +0300
@@ -174,6 +174,7 @@
     static long     cpu_total;
     long            cpu_sum;
     double          cpu_prc;
+    int		    mib[2], mib_len, cpu_new_len;
 
     static struct vmmeter mem_old, mem_new;
 
@@ -195,7 +196,10 @@
         /*
          * CPU usage 
          */
-        auto_nlist(CPTIME_SYMBOL, (char *) cpu_new, sizeof(cpu_new));
+	mib_len = 2;
+	sysctlnametomib("kern.cp_time", mib, &mib_len);
+	cpu_new_len = sizeof(cpu_new);
+	sysctl(mib, mib_len, cpu_new, &cpu_new_len, NULL, 0);
 
         cpu_total = 0;
 
