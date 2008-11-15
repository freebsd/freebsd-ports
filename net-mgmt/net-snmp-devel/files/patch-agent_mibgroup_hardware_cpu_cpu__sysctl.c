--- agent/mibgroup/hardware/cpu/cpu_sysctl.c.orig	2008-05-27 21:47:30.000000000 +0900
+++ agent/mibgroup/hardware/cpu/cpu_sysctl.c	2008-11-14 16:41:12.000000000 +0900
@@ -16,6 +16,8 @@
 #if !defined(CPUSTATES)
 #include <sys/dkstat.h>
 #endif
+#elif defined(__FreeBSD__)
+#define NETSNMP_KERN_CPU  0               /* FreeBSD - dummy value, sysctlnametomib(2) should be used */
 #else
 #include <sys/sched.h>
 #endif
@@ -117,7 +119,7 @@
     #define NS_VM_SWAPIN	v_swapin
     #define NS_VM_SWAPOUT	v_swapout
 
-#elif defined(VM_METER)                   /* OpenBSD, NetBSD */
+#elif defined(VM_METER) && !defined(__FreeBSD__)                   /* OpenBSD, NetBSD */
 #define NETSNMP_VM_STATS       VM_METER
 #define NETSNMP_VM_STATS_TYPE  struct vmtotal
 
@@ -130,6 +132,15 @@
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
 
 
