--- turbostat.c.orig	2020-11-13 21:55:04 UTC
+++ turbostat.c
@@ -41,7 +41,34 @@
 #include <sched.h>
 #include <time.h>
 #include <cpuid.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/cpuctl.h>
+#include <sys/cpuset.h>
+#include <sys/ioctl.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <elf.h>
+#include <libutil.h>
+#include <limits.h>
+
+#ifndef CPU_ALLOC
+#define CPUSET_2ADDR
+#define cpu_set_t cpuset_t
+
+#define CPU_ALLOC(_ign)			({(cpuset_t*)malloc(sizeof(cpuset_t));})
+#define CPU_ALLOC_SIZE(_ign)		sizeof(cpuset_t)
+#define CPU_FREE			free
+#define CPU_ISSET_S(cpu, _ign, set)	(set && CPU_ISSET(cpu, set))
+#define CPU_SET_S(cpu, _ign, set)	CPU_SET(cpu, set)
+#define CPU_ZERO_S(_ign, set)		CPU_ZERO(set)
+#define sched_setaffinity(_x, _y, set)	cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1, sizeof(cpuset_t), set)
+#endif /* !CPU_ALLOC */
+
+#else
 #include <linux/capability.h>
+#endif
 #include <errno.h>
 
 char *proc_stat = "/proc/stat";
@@ -132,7 +156,9 @@ unsigned int has_misc_feature_control;
 #define RAPL_CORES (RAPL_CORES_ENERGY_STATUS | RAPL_CORES_POWER_LIMIT)
 #define	TJMAX_DEFAULT	100
 
+#ifndef __FreeBSD__
 #define MAX(a, b) ((a) > (b) ? (a) : (b))
+#endif
 
 /*
  * buffer size used by sscanf() for added column names
@@ -309,6 +335,7 @@ int cpu_migrate(int cpu)
 	else
 		return 0;
 }
+
 int get_msr_fd(int cpu)
 {
 	char pathname[32];
@@ -319,18 +346,39 @@ int get_msr_fd(int cpu)
 	if (fd)
 		return fd;
 
+#ifdef __FreeBSD__
+	sprintf(pathname, "/dev/cpuctl%d", cpu);
+#else
 	sprintf(pathname, "/dev/cpu/%d/msr", cpu);
+#endif
 	fd = open(pathname, O_RDONLY);
 	if (fd < 0)
-		err(-1, "%s open failed, try chown or chmod +r /dev/cpu/*/msr, or run as root", pathname);
+		err(-1, "%s open failed, try chown or chmod +r "
+#ifdef __FreeBSD__
+		    "/dev/cpuctl*"
+#else
+		    "/dev/cpu/*/msr"
+#endif
+		    ", or run as root", pathname);
 
 	fd_percpu[cpu] = fd;
 
 	return fd;
 }
 
+#ifdef __FreeBSD__
 int get_msr(int cpu, off_t offset, unsigned long long *msr)
 {
+	cpuctl_msr_args_t args;
+	args.msr = offset;
+	if (ioctl(get_msr_fd(cpu), CPUCTL_RDMSR, &args))
+		err(1, "cpu%d: msr offset 0x%llx read failed", cpu, (unsigned long long)offset);
+	*msr = args.data;
+	return 0;
+}
+#else
+int get_msr(int cpu, off_t offset, unsigned long long *msr)
+{
 	ssize_t retval;
 
 	retval = pread(get_msr_fd(cpu), msr, sizeof(*msr), offset);
@@ -340,6 +388,7 @@ int get_msr(int cpu, off_t offset, unsigned long long 
 
 	return 0;
 }
+#endif
 
 /*
  * Each string in this array is compared in --show and --hide cmdline.
@@ -2239,6 +2288,181 @@ int parse_int_file(const char *fmt, ...)
 	return value;
 }
 
+#ifdef __FreeBSD__
+static int ncpus;
+struct cpuset_list {
+	cpuset_t	*sets;
+	size_t		len;
+	size_t		cap;
+};
+static struct cpuset_list packages = {0};
+static struct cpuset_list cores = {0};
+
+static void cpuset_list_ensure_space(struct cpuset_list *list) {
+	if (list->cap > list->len)
+		return;
+
+	if (list->cap)
+		list->cap *= 2;
+	else
+		list->cap = 2;
+
+	list->sets = realloc(list->sets, list->cap * sizeof(cpuset_t));
+}
+
+static cpuset_t parse_cpu_mask(const char *i) {
+	int count, mask_offset;
+	i = strstr(i, "mask=\"");
+	if (!i)
+		errx(1, "failed to parse topology_spec");
+	i += sizeof("mask=\"") - 1;
+
+	char sep;
+	cpuset_t out;
+	uint64_t *_out = (uint64_t *)&out;
+	CPU_ZERO(&out);
+
+	do {
+		int len;
+                if (sscanf(i, "%lx%c%n", _out, &sep, &len) != 2)
+			errx(1, "failed to parse topology_spec");
+                _out++;
+                i += len;
+	} while (sep == ',');
+
+	return out;
+}
+
+static void read_topology_spec(void)
+{
+	char *spec, *i;
+	size_t sz = 0;
+	if (sysctlbyname("kern.sched.topology_spec", NULL, &sz, NULL, 0) != 0 && errno != ENOMEM)
+		err(1, "sysctl: kern.sched.topology_spec: failed");
+	spec = malloc(sz);
+	if (spec == NULL)
+		err(1, "malloc: failed");
+	if (sysctlbyname("kern.sched.topology_spec", spec, &sz, NULL, 0))
+		err(1, "sysctl: kern.sched.topology_spec: failed");
+
+	/* Skip the entire system entry. */
+	i = strstr(spec, "<cpu");
+	if (!i)
+		errx(1, "read_topology_spec: parse failed");
+
+	cpuset_t last;
+	CPU_ZERO(&last);
+
+	while ((i = strstr(i + 1, "<cpu")) != NULL) {
+		cpuset_t set = parse_cpu_mask(i);
+
+		if (CPU_OVERLAP(&last, &set)) {
+			cpuset_list_ensure_space(&packages);
+			cores.len--;
+			CPU_COPY(cores.sets + cores.len, packages.sets + packages.len);
+			packages.len++;
+		}
+
+		cpuset_list_ensure_space(&cores);
+		CPU_COPY(&set, cores.sets + cores.len);
+		cores.len++;
+		CPU_COPY(&set, &last);
+	}
+
+	if (!packages.len) {
+		cpuset_list_ensure_space(&packages);
+		CPU_ZERO(packages.sets);
+
+		for (int i = 0; i < cores.len; i++)
+#ifdef CPUSET_2ADDR
+			CPU_OR(packages.sets, cores.sets + i);
+#else
+			CPU_OR(packages.sets, packages.sets, cores.sets + i);
+#endif
+		packages.len++;
+	}
+
+	ncpus = 0;
+	for (int i = 0; i < packages.len; i++)
+		ncpus += CPU_COUNT(packages.sets + i);
+
+	free(spec);
+}
+
+static int get_physical_package_id(int cpu)
+{
+	for (int i = 0; i < packages.len; i++) {
+		if (!CPU_ISSET(cpu, packages.sets + i))
+			continue;
+
+		return i;
+	}
+	return -1;
+}
+
+static int get_core_id(int cpu)
+{
+	int package_id = get_physical_package_id(cpu);
+	if (package_id < 0)
+		return -1;
+
+	const cpuset_t *package = packages.sets + package_id;
+
+	for (int i = 0, j = -1; i < cores.len; i++) {
+		if (CPU_OVERLAP(package, cores.sets + i))
+			j++;
+
+		if (!CPU_ISSET(cpu, cores.sets + i))
+			continue;
+
+		return j;
+	}
+	return -1;
+}
+
+static int get_cpu_position_in_core(int cpu)
+{
+	for (int i = 0; i < cores.len; i++) {
+		if (!CPU_ISSET(cpu, cores.sets + i))
+			continue;
+
+		cpuset_t s;
+		CPU_COPY(cores.sets + i, &s);
+		for (int j = 0; !CPU_EMPTY(&s); j++) {
+			int ffs = CPU_FFS(&s) - 1;
+			if (ffs == cpu)
+				return j;
+			CPU_CLR(ffs, &s);
+		}
+
+		return -1;
+	}
+
+	return -1;
+}
+
+static int get_num_ht_siblings(int cpu)
+{
+	for (int i = 0; i < cores.len; i++) {
+		if (!CPU_ISSET(cpu, cores.sets + i))
+			continue;
+
+		return CPU_COUNT(cores.sets + i);
+	}
+
+	return 1;
+}
+
+static int cpu_is_first_core_in_package(int cpu)
+{
+	int package = get_physical_package_id(cpu);
+	if (package < 0)
+		return -1;
+
+	return CPU_FFS(packages.sets + package) - 1 == cpu;
+}
+
+#else
 /*
  * get_cpu_position_in_core(cpu)
  * return the position of the CPU among its HT siblings in the core
@@ -2326,6 +2546,7 @@ int get_num_ht_siblings(int cpu)
 	fclose(filep);
 	return matches+1;
 }
+#endif
 
 /*
  * run func(thread, core, package) in topology order
@@ -2371,6 +2592,22 @@ int for_all_cpus_2(int (func)(struct thread_data *, st
 	return 0;
 }
 
+#ifdef __FreeBSD__
+int for_all_proc_cpus(int (func)(int))
+{
+	int retval;
+
+	if (!ncpus)
+		read_topology_spec();
+
+	for (long i = 0; i < ncpus; i++) {
+		retval = func(i);
+		if (retval)
+			return retval;
+	}
+	return 0;
+}
+#else
 /*
  * run func(cpu) on every cpu in /proc/stat
  * return max_cpu number
@@ -2401,6 +2638,7 @@ int for_all_proc_cpus(int (func)(int))
 	fclose(fp);
 	return 0;
 }
+#endif
 
 void re_initialize(void)
 {
@@ -2428,6 +2666,85 @@ int mark_cpu_present(int cpu)
 	return 0;
 }
 
+#ifdef __FreeBSD__
+static struct {
+	uint64_t intr_num;
+	uint64_t cpu_num;
+} *intr_map = NULL;
+static size_t intr_map_len = 0;
+static size_t intr_map_cap = 0;
+
+static void ensure_intr_map(void)
+{
+	if (intr_map_cap > intr_map_len)
+		return;
+
+	if (intr_map_cap)
+		intr_map_cap *= 2;
+	else
+		intr_map_cap = 2;
+
+	intr_map = realloc(intr_map, intr_map_cap * sizeof(*intr_map));
+}
+
+static void init_intr_map(void)
+{
+	size_t sz = 0;
+	if (sysctlbyname("hw.intrs", NULL, &sz, NULL, 0)) {
+		warn("sysctl: hw.intrs: per-cpu interrupt data will be unavailable");
+		return;
+	}
+	char *intrs = alloca(sz);
+	if (sysctlbyname("hw.intrs", intrs, &sz, NULL, 0)) {
+		warn("sysctl: hw.intrs: per-cpu interrupt data will be unavailable");
+		return;
+	}
+
+	char *i = intrs;
+	char *j;
+	while ((j = strstr(i, "@cpu")) != NULL) {
+		char *k;
+		for (k = j; k > i && *k != ':'; k--)
+			;
+		if (*k != ':')
+			errx(1, "init_intr_map: parse failed");
+		k++;
+		uint64_t intr_num;
+		if (sscanf(k, "%ld", &intr_num) != 1)
+			errx(1, "init_intr_map: parse failed");
+		j += 4;
+		uint64_t cpu_num;
+		if (sscanf(j, "%ld", &cpu_num) != 1)
+			errx(1, "init_intr_map: parse failed");
+		ensure_intr_map();
+		intr_map[intr_map_len].intr_num = intr_num;
+		intr_map[intr_map_len].cpu_num = cpu_num;
+		intr_map_len++;
+
+		i = j;
+	}
+}
+
+static int snapshot_proc_interrupts(void)
+{
+	if (!intr_map)
+		init_intr_map();
+
+	size_t sz = 0;
+	if (sysctlbyname("hw.intrcnt", NULL, &sz, NULL, 0))
+		err(1, "sysctl: hw.intrcnt: failed");
+	uint64_t *intrcnt = alloca(sz);
+	if (sysctlbyname("hw.intrcnt", intrcnt, &sz, NULL, 0))
+		err(1, "sysctl: hw.intrcnt: failed");
+
+	for (int i = 0; i < topo.num_cpus; i++)
+		irqs_per_cpu[i] = 0;
+	for (int i = 0; i < intr_map_len; i++)
+		irqs_per_cpu[intr_map[i].cpu_num] += intrcnt[intr_map[i].intr_num];
+
+	return 0;
+}
+#else
 /*
  * snapshot_proc_interrupts()
  *
@@ -2491,6 +2808,8 @@ int snapshot_proc_interrupts(void)
 	}
 	return 0;
 }
+#endif
+
 /*
  * snapshot_gfx_rc6_ms()
  *
@@ -2629,6 +2948,18 @@ restart:
 	}
 }
 
+#ifdef __FreeBSD__
+#define check_dev_msr()
+
+void check_permissions()
+{
+	if (eaccess("/dev/cpuctl0", F_OK))
+		err(errno, "/dev/cpuctl0 missing, kldload cpuctl");
+	if (eaccess("/dev/cpuctl0", R_OK))
+		err(errno, "cannot read /dev/cpuctl0, (run as root?)");
+}
+
+#else
 void check_dev_msr()
 {
 	struct stat sb;
@@ -2677,6 +3008,7 @@ void check_permissions()
 	if (do_exit)
 		exit(-6);
 }
+#endif
 
 /*
  * NHM adds support for additional MSRs:
@@ -4520,8 +4852,21 @@ void setup_all_buffers(void)
 	for_all_proc_cpus(initialize_counters);
 }
 
+#ifdef __FreeBSD__
 void set_base_cpu(void)
 {
+	struct kinfo_proc *proc = kinfo_getproc(getpid());
+	if (!proc || proc->ki_oncpu == NOCPU)
+		err(-ENODEV, "Failed to lookup curcpu");
+	base_cpu = proc->ki_oncpu;
+	free(proc);
+
+	if (debug > 1)
+		fprintf(outf, "base_cpu = %d\n", base_cpu);
+}
+#else
+void set_base_cpu(void)
+{
 	base_cpu = sched_getcpu();
 	if (base_cpu < 0)
 		err(-ENODEV, "No valid cpus found");
@@ -4529,6 +4874,7 @@ void set_base_cpu(void)
 	if (debug > 1)
 		fprintf(outf, "base_cpu = %d\n", base_cpu);
 }
+#endif
 
 void turbostat_init()
 {
