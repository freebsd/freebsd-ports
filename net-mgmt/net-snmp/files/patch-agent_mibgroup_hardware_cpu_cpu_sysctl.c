--- agent/mibgroup/hardware/cpu/cpu_sysctl.c.orig	2014-12-08 12:23:22.000000000 -0800
+++ agent/mibgroup/hardware/cpu/cpu_sysctl.c	2017-04-20 15:05:11.607496000 -0700
@@ -130,8 +130,21 @@
 #endif  /* VM_UVMEXP2 || VM_UVMEXP */
 
 #elif defined(__FreeBSD__)                /* FreeBSD */
+#if __FreeBSD_version >= 1200028
+#define	VMMETER_TYPE	uint64_t
+#else
+#define	VMMETER_TYPE	u_int
+#endif
+struct __vmmeter {
+	VMMETER_TYPE	v_intr;
+	VMMETER_TYPE	v_swtch;
+	VMMETER_TYPE	v_swappgsin;
+	VMMETER_TYPE	v_swappgsout;
+	VMMETER_TYPE	v_swapin;
+	VMMETER_TYPE	v_swapout;
+};
 #define NETSNMP_VM_STATS       VM_METER
-#define NETSNMP_VM_STATS_TYPE  struct vmmeter
+#define NETSNMP_VM_STATS_TYPE  struct __vmmeter
     #define NS_VM_INTR		v_intr
     #define NS_VM_SWTCH		v_swtch
     #define NS_VM_PAGEIN	v_swappgsin
@@ -206,7 +219,23 @@
          * Interrupt/Context Switch statistics
          *   XXX - Do these really belong here ?
          */
+#ifdef __FreeBSD__
+#define	GET_VM_STATS(space, name) sysctlbyname("vm.stats." #space "." #name, &mem_stats.name, &len, NULL, 0)
+    {
+	size_t len;
+
+	len = sizeof(VMMETER_TYPE);
+	GET_VM_STATS(sys, v_intr);
+	GET_VM_STATS(sys, v_swtch);
+	GET_VM_STATS(vm, v_swappgsin);
+	GET_VM_STATS(vm, v_swappgsout);
+	GET_VM_STATS(vm, v_swapin);
+	GET_VM_STATS(vm, v_swapout);
+    }
+#undef GET_VM_STATS
+#else
     sysctl(mem_mib, 2, &mem_stats, &mem_size, NULL, 0);
+#endif
     cpu->nInterrupts  = mem_stats.NS_VM_INTR;
     cpu->nCtxSwitches = mem_stats.NS_VM_SWTCH;
     cpu->swapIn       = mem_stats.NS_VM_SWAPIN;
