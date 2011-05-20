
$FreeBSD$

--- libmetrics/freebsd/metrics.c.orig
+++ libmetrics/freebsd/metrics.c
@@ -170,9 +170,21 @@
    size_t len;
    uint32_t freq = 0, tmpfreq;
    uint64_t tscfreq;
+   unsigned int cpu_freq;
 
    /*
-    * If the system supports it, the cpufreq driver provides the best
+    * Try the portable sysctl (introduced on ia64).
+    */
+   cpu_freq = 0;
+   len = sizeof(cpu_freq);
+   if (sysctlbyname("hw.freq.cpu", &cpu_freq, &len, NULL, 0) != -1 &&
+       cpu_freq != 0) {
+      freq = cpu_freq;
+      goto done;
+   }
+
+   /*
+    * If the system supports it, the cpufreq driver provides
     * access to CPU frequency.  Since we want a constant value, we're
     * looking for the maximum frequency, not the current one.  We
     * don't know what order the driver will report values in so we
@@ -529,6 +541,17 @@
       goto output;
 
    for (i = 0; i < nentries; kp++, i++) {
+      /* This is a per-CPU idle thread. */ /* idle thread */
+      if ((kp->ki_tdflags & TDF_IDLETD) != 0)
+         continue;
+      /* Ignore during load avg calculations. */ /* swi or idle thead */
+#ifdef TDF_NOLOAD
+      /* Introduced in FreeBSD 8.3 */
+      if ((kp->ki_tdflags & TDF_NOLOAD) != 0)
+#else
+      if ((kp->ki_flag & P_NOLOAD) != 0)
+#endif
+         continue;
 #ifdef KINFO_PROC_SIZE
       state = kp->ki_stat;
 #else
