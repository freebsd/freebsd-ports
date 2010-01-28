--- src/freebsd.c.orig	2009-08-09 00:05:55.000000000 +0400
+++ src/freebsd.c	2010-01-11 01:20:59.000000000 +0300
@@ -284,40 +284,38 @@
 	info.run_procs = cnt;
 }
 
-struct cpu_load_struct {
-	unsigned long load[5];
-};
-
-struct cpu_load_struct fresh = { {0, 0, 0, 0, 0} };
-long cpu_used, oldtotal, oldused;
-
 void get_cpu_count(void)
 {
-	/* int cpu_count = 0; */
+	int cpu_count = 0;
+	size_t cpu_count_len = sizeof(cpu_count);
 
-	/* XXX: FreeBSD doesn't allow to get per CPU load stats on SMP machines.
-	 * It's possible to get a CPU count, but as we fulfill only
-	 * info.cpu_usage[0], it's better to report there's only one CPU.
-	 * It should fix some bugs (e.g. cpugraph) */
-#if 0
 	if (GETSYSCTL("hw.ncpu", cpu_count) == 0) {
 		info.cpu_count = cpu_count;
+	} else {
+		fprintf(stderr, "Cannot get hw.ncpu\n");
+		info.cpu_count = 0;
 	}
-#endif
-	info.cpu_count = 1;
 
-	info.cpu_usage = malloc(info.cpu_count * sizeof(float));
+	info.cpu_usage = malloc((info.cpu_count + 1) * sizeof(float));
 	if (info.cpu_usage == NULL) {
 		CRIT_ERR(NULL, NULL, "malloc");
 	}
 }
 
-/* XXX: SMP support */
+struct cpu_info {
+	long oldtotal;
+	long oldused;
+};
+
 void update_cpu_usage(void)
 {
+	int i, j = 0;
 	long used, total;
-	long cp_time[CPUSTATES];
-	size_t cp_len = sizeof(cp_time);
+	long *cp_time = NULL;
+	size_t cp_len;
+	static struct cpu_info *cpu = NULL;
+	unsigned int malloc_cpu_size = 0;
+	extern void* global_cpu;
 
 	/* add check for !info.cpu_usage since that mem is freed on a SIGUSR1 */
 	if ((cpu_setup == 0) || (!info.cpu_usage)) {
@@ -325,28 +323,68 @@
 		cpu_setup = 1;
 	}
 
-	if (sysctlbyname("kern.cp_time", &cp_time, &cp_len, NULL, 0) < 0) {
-		fprintf(stderr, "Cannot get kern.cp_time");
+	if (!global_cpu) {
+		malloc_cpu_size = (info.cpu_count + 1) * sizeof(struct cpu_info);
+		cpu = malloc(malloc_cpu_size);
+		memset(cpu, 0, malloc_cpu_size);
+		global_cpu = cpu;
+	}
+
+	/* cpu[0] is overall stats, get it from separate sysctl */
+	cp_len = CPUSTATES * sizeof(long);
+	cp_time = malloc(cp_len);
+
+	if (sysctlbyname("kern.cp_time", cp_time, &cp_len, NULL, 0) < 0) {
+		fprintf(stderr, "Cannot get kern.cp_time\n");
 	}
 
-	fresh.load[0] = cp_time[CP_USER];
-	fresh.load[1] = cp_time[CP_NICE];
-	fresh.load[2] = cp_time[CP_SYS];
-	fresh.load[3] = cp_time[CP_IDLE];
-	fresh.load[4] = cp_time[CP_IDLE];
-
-	used = fresh.load[0] + fresh.load[1] + fresh.load[2];
-	total = fresh.load[0] + fresh.load[1] + fresh.load[2] + fresh.load[3];
-
-	if ((total - oldtotal) != 0) {
-		info.cpu_usage[0] = ((double) (used - oldused)) /
-			(double) (total - oldtotal);
+	total = 0;
+	for (j = 0; j < CPUSTATES; j++)
+		total += cp_time[j];
+
+	used = total - cp_time[CP_IDLE];
+
+	if ((total - cpu[0].oldtotal) != 0) {
+		info.cpu_usage[0] = ((double) (used - cpu[0].oldused)) /
+		(double) (total - cpu[0].oldtotal);
 	} else {
 		info.cpu_usage[0] = 0;
 	}
 
-	oldused = used;
-	oldtotal = total;
+	cpu[0].oldused = used;
+	cpu[0].oldtotal = total;
+
+	free(cp_time);
+
+	/* per-core stats */
+	cp_len = CPUSTATES * sizeof(long) * info.cpu_count;
+	cp_time = malloc(cp_len);
+
+	/* on e.g. i386 SMP we may have more values than actual cpus; this will just drop extra values */
+	if (sysctlbyname("kern.cp_times", cp_time, &cp_len, NULL, 0) < 0 && errno != ENOMEM) {
+		fprintf(stderr, "Cannot get kern.cp_times\n");
+	}
+
+	for (i = 0; i < info.cpu_count; i++)
+	{
+		total = 0;
+		for (j = 0; j < CPUSTATES; j++)
+			total += cp_time[i*CPUSTATES + j];
+
+		used = total - cp_time[i*CPUSTATES + CP_IDLE];
+
+		if ((total - cpu[i+1].oldtotal) != 0) {
+			info.cpu_usage[i+1] = ((double) (used - cpu[i+1].oldused)) /
+			(double) (total - cpu[i+1].oldtotal);
+		} else {
+			info.cpu_usage[i+1] = 0;
+		}
+
+		cpu[i+1].oldused = used;
+		cpu[i+1].oldtotal = total;
+	}
+
+	free(cp_time);
 }
 
 void update_load_average(void)
