--- src/freebsd.c.orig
+++ src/freebsd.c
@@ -67,7 +67,7 @@
 #endif
 
 __attribute__((gnu_inline)) inline void
-proc_find_top(struct process **cpu, struct process **mem);
+proc_find_top(struct process **cpu, struct process **mem, struct process **time);
 
 static short cpu_setup = 0;
 
@@ -118,7 +118,7 @@ void prepare_update(void)
 {
 }
 
-void update_uptime(void)
+int update_uptime(void)
 {
 	int mib[2] = { CTL_KERN, KERN_BOOTTIME };
 	struct timeval boottime;
@@ -133,6 +133,8 @@ void update_uptime(void)
 		fprintf(stderr, "Could not get uptime\n");
 		info.uptime = 0;
 	}
+
+	return 0;
 }
 
 int check_mount(char *s)
@@ -150,7 +152,7 @@ int check_mount(char *s)
 	return 0;
 }
 
-void update_meminfo(void)
+int update_meminfo(void)
 {
 	u_int total_pages, inactive_pages, free_pages;
 	unsigned long swap_avail, swap_free;
@@ -182,9 +184,11 @@ void update_meminfo(void)
 		info.swap = 0;
 		info.swapfree = 0;
 	}
+
+	return 0;
 }
 
-void update_net_stats(void)
+int update_net_stats(void)
 {
 	struct net_stat *ns;
 	double delta;
@@ -195,11 +199,11 @@ void update_net_stats(void)
 	/* get delta */
 	delta = current_update_time - last_update_time;
 	if (delta <= 0.0001) {
-		return;
+		return 0;
 	}
 
 	if (getifaddrs(&ifap) < 0) {
-		return;
+		return 0;
 	}
 
 	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
@@ -255,18 +259,20 @@ void update_net_stats(void)
 	}
 
 	freeifaddrs(ifap);
+	return 0;
 }
 
-void update_total_processes(void)
+int update_total_processes(void)
 {
 	int n_processes;
 
 	kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
 
 	info.procs = n_processes;
+	return 0;
 }
 
-void update_running_processes(void)
+int update_running_processes(void)
 {
 	struct kinfo_proc *p;
 	int n_processes;
@@ -284,42 +290,41 @@ void update_running_processes(void)
 	}
 
 	info.run_procs = cnt;
+	return 0;
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
-void update_cpu_usage(void)
+struct cpu_info {
+	long oldtotal;
+	long oldused;
+};
+
+int update_cpu_usage(void)
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
@@ -327,31 +332,72 @@ void update_cpu_usage(void)
 		cpu_setup = 1;
 	}
 
-	if (sysctlbyname("kern.cp_time", &cp_time, &cp_len, NULL, 0) < 0) {
-		fprintf(stderr, "Cannot get kern.cp_time");
+	if (!global_cpu) {
+		malloc_cpu_size = (info.cpu_count + 1) * sizeof(struct cpu_info);
+		cpu = malloc(malloc_cpu_size);
+		memset(cpu, 0, malloc_cpu_size);
+		global_cpu = cpu;
 	}
 
-	fresh.load[0] = cp_time[CP_USER];
-	fresh.load[1] = cp_time[CP_NICE];
-	fresh.load[2] = cp_time[CP_SYS];
-	fresh.load[3] = cp_time[CP_IDLE];
-	fresh.load[4] = cp_time[CP_IDLE];
+	/* cpu[0] is overall stats, get it from separate sysctl */
+	cp_len = CPUSTATES * sizeof(long);
+	cp_time = malloc(cp_len);
 
-	used = fresh.load[0] + fresh.load[1] + fresh.load[2];
-	total = fresh.load[0] + fresh.load[1] + fresh.load[2] + fresh.load[3];
+	if (sysctlbyname("kern.cp_time", cp_time, &cp_len, NULL, 0) < 0) {
+		fprintf(stderr, "Cannot get kern.cp_time\n");
+	}
+
+	total = 0;
+	for (j = 0; j < CPUSTATES; j++)
+		total += cp_time[j];
 
-	if ((total - oldtotal) != 0) {
-		info.cpu_usage[0] = ((double) (used - oldused)) /
-			(double) (total - oldtotal);
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
+	return 0;
 }
 
-void update_load_average(void)
+int update_load_average(void)
 {
 	double v[3];
 
@@ -360,6 +406,8 @@ void update_load_average(void)
 	info.loadavg[0] = (double) v[0];
 	info.loadavg[1] = (double) v[1];
 	info.loadavg[2] = (double) v[2];
+
+	return 0;
 }
 
 double get_acpi_temperature(int fd)
@@ -540,9 +588,10 @@ char get_freq(char *p_client_buffer, size_t client_buffer_size, const char *p_fo
 	return 1;
 }
 
-void update_top(void)
+int update_top(void)
 {
-	proc_find_top(info.cpu, info.memu);
+	proc_find_top(info.cpu, info.memu, info.time);
+	return 0;
 }
 
 #if 0
@@ -600,7 +649,7 @@ cleanup:
 }
 #endif
 
-void update_diskio(void)
+int update_diskio(void)
 {
 	int devs_count, num_selected, num_selections, dn;
 	struct device_selection *dev_select = NULL;
@@ -618,7 +667,7 @@ void update_diskio(void)
 
 	if (devstat_getdevs(NULL, &statinfo_cur) < 0) {
 		free(statinfo_cur.dinfo);
-		return;
+		return 0;
 	}
 
 	devs_count = statinfo_cur.dinfo->numdevs;
@@ -650,6 +699,7 @@ void update_diskio(void)
 	}
 
 	free(statinfo_cur.dinfo);
+	return 0;
 }
 
 /* While topless is obviously better, top is also not bad. */
@@ -676,8 +726,15 @@ int comparemem(const void *a, const void *b)
 	}
 }
 
+int comparetime(const void *va, const void *vb)
+{
+	struct process *a = (struct process *)va, *b = (struct process *)vb;
+
+	return b->total_cpu_time - a->total_cpu_time;
+}
+
 __attribute__((gnu_inline)) inline void
-proc_find_top(struct process **cpu, struct process **mem)
+proc_find_top(struct process **cpu, struct process **mem, struct process **time)
 {
 	struct kinfo_proc *p;
 	int n_processes;
@@ -701,6 +758,9 @@ proc_find_top(struct process **cpu, struct process **mem)
 			processes[j].amount = 100.0 * p[i].ki_pctcpu / FSCALE;
 			processes[j].vsize = p[i].ki_size;
 			processes[j].rss = (p[i].ki_rssize * getpagesize());
+			/* ki_runtime is in microseconds, total_cpu_time in centiseconds.
+			 * Therefore we divide by 10000. */
+			processes[j].total_cpu_time = p[i].ki_runtime / 10000;
 			j++;
 		}
 	}
@@ -710,11 +770,8 @@ proc_find_top(struct process **cpu, struct process **mem)
 		struct process *tmp, *ttmp;
 
 		tmp = malloc(sizeof(struct process));
-		tmp->pid = processes[i].pid;
-		tmp->amount = processes[i].amount;
+		memcpy(tmp, &processes[i], sizeof(struct process));
 		tmp->name = strndup(processes[i].name, text_buffer_size);
-		tmp->rss = processes[i].rss;
-		tmp->vsize = processes[i].vsize;
 
 		ttmp = mem[i];
 		mem[i] = tmp;
@@ -729,11 +786,8 @@ proc_find_top(struct process **cpu, struct process **mem)
 		struct process *tmp, *ttmp;
 
 		tmp = malloc(sizeof(struct process));
-		tmp->pid = processes[i].pid;
-		tmp->amount = processes[i].amount;
+		memcpy(tmp, &processes[i], sizeof(struct process));
 		tmp->name = strndup(processes[i].name, text_buffer_size);
-		tmp->rss = processes[i].rss;
-		tmp->vsize = processes[i].vsize;
 
 		ttmp = cpu[i];
 		cpu[i] = tmp;
@@ -743,6 +797,22 @@ proc_find_top(struct process **cpu, struct process **mem)
 		}
 	}
 
+	qsort(processes, j - 1, sizeof(struct process), comparetime);
+	for (i = 0; i < 10 && i < n_processes; i++) {
+		struct process *tmp, *ttmp;
+
+		tmp = malloc(sizeof(struct process));
+		memcpy(tmp, &processes[i], sizeof(struct process));
+		tmp->name = strndup(processes[i].name, text_buffer_size);
+
+		ttmp = time[i];
+		time[i] = tmp;
+		if (ttmp != NULL) {
+			free(ttmp->name);
+			free(ttmp);
+		}
+	}
+
 #if defined(FREEBSD_DEBUG)
 	printf("=====\nmem\n");
 	for (i = 0; i < 10; i++) {
@@ -916,8 +986,3 @@ int get_entropy_poolsize(unsigned int *val)
 	(void)val;
 	return 1;
 }
-
-/* empty stub so conky links */
-void free_all_processes(void)
-{
-}
