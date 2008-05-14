
$FreeBSD$

--- agent/mibgroup/hardware/cpu/cpu_sysctl.c.orig
+++ agent/mibgroup/hardware/cpu/cpu_sysctl.c
@@ -11,7 +11,14 @@
 #include <unistd.h>
 #include <sys/types.h>
 
+#if defined(__FreeBSD__)
+#include <sys/resource.h>
+#if !defined(CPUSTATES)
+#include <sys/dkstat.h>
+#endif
+#else
 #include <sys/sched.h>
+#endif
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
@@ -37,11 +44,11 @@
     strcpy(cpu->name, "Overall CPU statistics");
 
     i = sizeof(n);
-    sysctl(ncpu_mib, 2, &n, &i, NULL, 0);
+    sysctl(ncpu_mib, 2, &n, (void *)&i, NULL, 0);
     if ( n <= 0 )
         n = 1;   /* Single CPU system */
     i = sizeof(descr);
-    sysctl(model_mib, 2, descr, &i, NULL, 0);
+    sysctl(model_mib, 2, descr, (void *)&i, NULL, 0);
     for ( i = 0; i < n; i++ ) {
         cpu = netsnmp_cpu_get_byIdx( i, 1 );
         cpu->status = 2;  /* running */
@@ -64,6 +71,8 @@
 #undef  NETSNMP_CPU_STATS 
 #define NETSNMP_CPU_STATS uint64_t
 #endif
+#elif defined(__FreeBSD__)
+#define NETSNMP_KERN_CPU  0               /* FreeBSD - dummy value, sysctlnametomib(2) should be used */
 #else
 #error "No CPU statistics sysctl token"
 #endif
@@ -95,7 +104,7 @@
 #define NETSNMP_VM_STATS_TYPE  struct uvmexp
 #endif  /* VM_UVMEXP2 || VM_UVMEXP */
 
-#elif defined(VM_METER)                   /* OpenBSD, NetBSD, FreeBSD */
+#elif defined(VM_METER) && !defined(__FreeBSD__)                   /* OpenBSD, NetBSD */
 #define NETSNMP_VM_STATS       VM_METER
 #define NETSNMP_VM_STATS_TYPE  struct vmtotal
 
@@ -108,6 +117,15 @@
     #undef  NS_VM_PAGEOUT
     #define NS_VM_SWAPIN	v_swpin
     #define NS_VM_SWAPOUT	v_swpout
+#elif defined(__FreeBSD__)                   /* FreeBSD */
+#define NETSNMP_VM_STATS       VM_METER
+#define NETSNMP_VM_STATS_TYPE  struct vmmeter
+    #define NS_VM_INTR          v_intr
+    #define NS_VM_SWTCH         v_swtch
+    #define NS_VM_PAGEIN        v_swappgsin
+    #define NS_VM_PAGEOUT       v_swappgsout
+    #define NS_VM_SWAPIN        v_swapin
+    #define NS_VM_SWAPOUT       v_swapout
 #endif
 
 
@@ -126,7 +144,7 @@
      */
     NETSNMP_CPU_STATS cpu_stats[CPUSTATES];
     int            cpu_mib[] = { CTL_KERN, NETSNMP_KERN_CPU };
-    int            cpu_size  = sizeof(cpu_stats);
+    size_t         cpu_size  = sizeof(cpu_stats);
 #ifdef NETSNMP_KERN_MCPU 
     NETSNMP_KERN_MCPU_TYPE *mcpu_stats;
     int            mcpu_mib[] = { CTL_KERN, NETSNMP_KERN_MCPU };
@@ -134,10 +152,13 @@
 #endif
     NETSNMP_VM_STATS_TYPE mem_stats;
     int            mem_mib[] = { CTL_VM, NETSNMP_VM_STATS };
-    int            mem_size  = sizeof(NETSNMP_VM_STATS_TYPE);
+    size_t         mem_size  = sizeof(NETSNMP_VM_STATS_TYPE);
     netsnmp_cpu_info *cpu = netsnmp_cpu_get_byIdx( -1, 0 );
-
-    sysctl(cpu_mib, 2,  cpu_stats, &cpu_size, NULL, 0);
+#if defined(__FreeBSD__)
+    sysctlbyname("kern.cp_time", cpu_stats, &cpu_size, NULL, 0);
+#else
+    sysctl(cpu_time, 2, cpu_stats, &cpu_size, NULL, 0);
+#endif
     cpu->user_ticks = (unsigned long)cpu_stats[CP_USER];
     cpu->nice_ticks = (unsigned long)cpu_stats[CP_NICE];
     cpu->sys2_ticks = (unsigned long)cpu_stats[CP_SYS]+cpu_stats[CP_INTR];
