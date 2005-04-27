
$FreeBSD$

--- srclib/libmetrics/freebsd/metrics.c.orig
+++ srclib/libmetrics/freebsd/metrics.c
@@ -151,16 +151,51 @@
 cpu_speed_func ( void )
 {
    g_val_t val;
-   int cpu_speed;
-   size_t len = sizeof(cpu_speed);
+   char buf[1024];
+   char *curptr;
+   size_t len;
+   long freq = 0, tmpfreq;
 
    /*
-    * machdep.tsc_freq is an i386/amd64 only feature, but it's the best
-    * we've got at the moment.
+    * If the system supports it, the cpufreq driver provides the best
+    * access to CPU frequency.  Since we want a constant value, we're
+    * looking for the maximum frequency, not the current one.  We
+    * don't know what order the driver will report values in so we
+    * search for the highest one by parsing the string returned by the
+    * dev.cpu.0.freq_levels sysctl.  The format of the string is a space
+    * seperated list of MHz/milliwatts.
     */
-   if (sysctlbyname("machdep.tsc_freq", &cpu_speed, &len, NULL, 0) == -1)
-     cpu_speed = 0;
-   val.uint16 = cpu_speed /= 1000000;
+   tmpfreq = 0;
+   len = sizeof(buf);
+   if (sysctlbyname("dev.cpu.0.freq_levels", buf, &len, NULL, 0) == -1)
+      buf[0] = '\0';
+   curptr = buf;
+   while (isdigit(curptr[0])) {
+      freq = strtol(curptr, &curptr, 10);
+      if (freq > tmpfreq)
+	 tmpfreq = freq;
+      /* Skip the rest of this entry */
+      while (!isspace(curptr[0]) && curptr[0] != '\0')
+	 curptr++;
+      /* Find the next entry */
+      while (!isdigit(curptr[0]) && curptr[0] != '\0')
+	 curptr++;
+   }
+   freq = tmpfreq;
+   if (tmpfreq != 0)
+      goto done;
+
+   /*
+    * machdep.tsc_freq exists on some i386/amd64 machines and gives the
+    * CPU speed in Hz.  If it exists it's a decent value.
+    */
+   if (sysctlbyname("machdep.tsc_freq", &tmpfreq, &len, NULL, 0) != -1) {
+      freq = (double)tmpfreq / 1e6;
+      goto done;
+   }
+
+done:
+   val.uint32 = freq;
 
    return val;
 }
