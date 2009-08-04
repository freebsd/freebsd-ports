Index: src/sysdeps/freebsd.c
diff -u -p src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	2008-10-04 09:45:56.000000000 +0900
+++ src/sysdeps/freebsd.c	2009-08-04 22:04:06.080455360 +0900
@@ -33,14 +33,20 @@
 |  as that of the covered work.
 */
 
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <osreldate.h>
+
+#if __FreeBSD_version < 500000
 #include <kvm.h>
 
 kvm_t	*kvmd = NULL;
 char	errbuf[_POSIX2_LINE_MAX];
+#endif
 
 
 // extern gboolean force_meminfo_update(void);
-#if defined(__i386__)
+#if defined(__i386__) || defined(__amd64__)
 static void scan_for_sensors();
 #endif
 
@@ -51,13 +57,15 @@ gkrellm_sys_main_init(void)
 	/* We just ignore error, here.  Even if GKrellM doesn't have
 	|  kmem privilege, it runs with available information.
 	*/
+#if __FreeBSD_version < 500000
 	kvmd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, errbuf);
+#endif
 	if (setgid(getgid()) != 0)
 		{
 		fprintf(stderr, "Can't drop setgid privileges.");
 		exit(1);
 		}
-#if defined(__i386__)
+#if defined(__i386__) || defined(__amd64__)
 	scan_for_sensors();
 #endif
 	if (setuid(getuid()) != 0)
@@ -72,9 +80,6 @@ gkrellm_sys_main_cleanup(void)
 	{
 	}
 
-#include <sys/param.h>
-#include <sys/sysctl.h>
-
 static int
 gk_sysctlnametomib(const char *name, int *mibp, size_t *lenp)
 	{
@@ -90,38 +95,43 @@ gk_sysctlnametomib(const char *name, int
 /* ===================================================================== */
 /* CPU monitor interface */
 
-#include <osreldate.h>
 #if __FreeBSD_version >= 500101
 #include <sys/resource.h>
 #else
 #include <sys/dkstat.h>
 #endif
-#include <kvm.h>
-
-
-extern	kvm_t	*kvmd;
 
 static int	oid_cp_time[CTL_MAXNAME + 2];
+static int	oid_cp_times[CTL_MAXNAME + 2];
 static size_t	oid_cp_time_len = sizeof(oid_cp_time);
+static size_t	oid_cp_times_len = sizeof(oid_cp_times);
 static gint	have_cp_time;
+static gint	maxid;
+static gint	ncpus;
+static u_long	cpumask;
+static long	*cp_times;
 
 void
 gkrellm_sys_cpu_read_data(void)
 	{
-	long		cp_time[CPUSTATES];
-	int		len = sizeof(cp_time);
+	long		cp_time[CPUSTATES], *cp_timep;
+	size_t		len;
+#if __FreeBSD_version < 500000
 	static struct nlist nl[] = {
 #define N_CP_TIME	0
 		{ "_cp_time" },
 		{ "" }
 	};
+#endif
 
 	if (have_cp_time)
 		{
-		if (sysctl(oid_cp_time, oid_cp_time_len,
-			   cp_time, &len, 0, 0) < 0)
+		len = sizeof(cp_time);
+		if (sysctl(oid_cp_time, oid_cp_time_len, cp_time, &len,
+			   NULL, 0) < 0)
 			return;
 		}
+#if __FreeBSD_version < 500000
 	else
 		{
 		if (kvmd == NULL)
@@ -133,22 +143,92 @@ gkrellm_sys_cpu_read_data(void)
 			     sizeof(cp_time)) != sizeof(cp_time))
 			return;
 		}
+#endif
 
-	/* Currently, SMP is not supported */
-	gkrellm_cpu_assign_data(0, cp_time[CP_USER], cp_time[CP_NICE],
-				cp_time[CP_SYS], cp_time[CP_IDLE]);
+	if (ncpus > 1)
+		{
+		gint	i, j;
+
+		gkrellm_cpu_assign_composite_data(cp_time[CP_USER],
+						  cp_time[CP_NICE],
+						  cp_time[CP_SYS],
+						  cp_time[CP_IDLE]);
+
+		len = (maxid + 1) * sizeof(long) * CPUSTATES;
+		if (sysctl(oid_cp_times, oid_cp_times_len, cp_times, &len,
+			   NULL, 0) < 0)
+			return;
+		for (i = j = 0; i <= maxid; ++i)
+			{
+			if ((cpumask & (1ul << i)) == 0)
+				continue;
+			cp_timep = &cp_times[i * CPUSTATES];
+			gkrellm_cpu_assign_data(j, cp_timep[CP_USER],
+						cp_timep[CP_NICE],
+						cp_timep[CP_SYS],
+						cp_timep[CP_IDLE]);
+			++j;
+			}
+		}
+	else
+		gkrellm_cpu_assign_data(0, cp_time[CP_USER], cp_time[CP_NICE],
+					cp_time[CP_SYS], cp_time[CP_IDLE]);
 	}
 
 gboolean
 gkrellm_sys_cpu_init(void)
 	{
-	static char	*name = "kern.cp_time";
-
-	gkrellm_cpu_set_number_of_cpus(1);
+	gint	have_cp_times = FALSE;
+	gint	maxcpus;
+	size_t	len;
+	long	*p;
+
+	if (gk_sysctlnametomib("kern.cp_time", oid_cp_time,
+			       &oid_cp_time_len) >= 0)
+		have_cp_time = TRUE;
+
+	len = sizeof(maxcpus);
+	if (sysctlbyname("kern.smp.maxcpus", &maxcpus, &len, NULL, 0) >= 0)
+		{
+		gint	empty, i, j;
+
+		if (gk_sysctlnametomib("kern.cp_times", oid_cp_times,
+				       &oid_cp_times_len) < 0)
+			goto pcpu_probe_done;
+		len = maxcpus * sizeof(long) * CPUSTATES;
+		if ((cp_times = malloc(len)) == NULL)
+			goto pcpu_probe_done;
+		if (sysctl(oid_cp_times, oid_cp_times_len, cp_times, &len,
+			   NULL, 0) < 0)
+			{
+			free(cp_times);
+			cp_times = NULL;
+			goto pcpu_probe_done;
+			}
+		maxid = (len / CPUSTATES / sizeof(long)) - 1;
+		cpumask = 0;
+		ncpus = 0;
+		for (i = 0; i <= maxid; ++i)
+			{
+			empty = 1;
+			for (j = 0; empty && j < CPUSTATES; ++j)
+				if (cp_times[i * CPUSTATES + j] != 0)
+					empty = 0;
+			if (!empty)
+				{
+				cpumask |= (1ul << i);
+				++ncpus;
+				}
+			}
+		if ((p  = realloc(cp_times, len)) != NULL)
+			cp_times = p;
+		have_cp_times = TRUE;
+		}
 
-	if (gk_sysctlnametomib(name, oid_cp_time, &oid_cp_time_len) < 0)
-		return TRUE;
-	++have_cp_time;
+pcpu_probe_done:
+	if (!have_cp_times)
+		ncpus = 1;
+	gkrellm_cpu_set_number_of_cpus(ncpus);
 	return TRUE;
 	}
 
@@ -156,8 +236,6 @@ gkrellm_sys_cpu_init(void)
 /* ===================================================================== */
 /* Proc monitor interface */
 
-#include <osreldate.h>
-#include <sys/sysctl.h>
 #if __FreeBSD_version >= 400000
 #include <sys/user.h>
 #endif
@@ -175,13 +253,10 @@ gkrellm_sys_cpu_init(void)
 #undef KERNEL
 #endif
 
-#include <kvm.h>
 #include <limits.h>
 #include <paths.h>
 #include <utmp.h>
 
-extern	kvm_t	*kvmd;
-
 static int	oid_v_forks[CTL_MAXNAME + 2];
 static int	oid_v_vforks[CTL_MAXNAME + 2];
 static int	oid_v_rforks[CTL_MAXNAME + 2];
@@ -215,17 +290,19 @@ gkrellm_sys_proc_read_data(void)
 	static int	oid_proc[] = { CTL_KERN, KERN_PROC, KERN_PROC_ALL };
 #endif
 	double		avenrun;
-	static u_int	n_processes, n_forks = 0, curpid = -1;
+	static u_int	n_processes, n_forks = 0;
 	u_int		n_vforks, n_rforks;
 	gint		r_forks, r_vforks, r_rforks;
-	gint		len;
+	size_t		len;
+#if __FreeBSD_version < 500000
+	static u_int	curpid = -1;
 	gint		nextpid, nforked;
 	static struct nlist nl[] = {
 #define N_NEXTPID	0
 		{ "_nextpid" },
 		{ "" }
 	};
-
+#endif
 
 	if (getloadavg(&avenrun, 1) <= 0)
 		avenrun = 0;
@@ -246,6 +323,7 @@ gkrellm_sys_proc_read_data(void)
 		if (r_forks >= 0 && r_vforks >= 0 && r_rforks >= 0)
 			n_forks = n_forks + n_vforks + n_rforks;
 		}
+#if __FreeBSD_version < 500000
 	else
 		{
 		/* workaround: Can I get total number of processes? */
@@ -268,6 +346,7 @@ gkrellm_sys_proc_read_data(void)
 				}
 			}
 		}
+#endif
 
 #if __FreeBSD_version >= 400000
 	if (sysctl(oid_proc, 3, NULL, &len, NULL, 0) >= 0)
@@ -318,10 +397,6 @@ gkrellm_sys_proc_read_users(void)
 #if __FreeBSD_version >= 300000
 #include <devstat.h>
 static struct statinfo	statinfo_cur;
-#else
-#include <kvm.h>
-
-extern	kvm_t	*kvmd;
 #endif
 
 gchar *
@@ -479,11 +554,7 @@ gkrellm_sys_disk_init(void)
 #include <netinet6/tcp6_var.h>
 #endif
 
-#include <kvm.h>
 #include <nlist.h>
-
-extern	kvm_t	*kvmd;
-extern	char	errbuf[];
 #endif
 
 
@@ -582,7 +653,7 @@ gkrellm_sys_inet_read_tcp_data(void)
 	gint		tcp_status;
 	struct xinpgen	*xig, *oxig;
 	gchar		*buf;
-	gint		len = 0;
+	size_t		len = 0;
 
 	if (!initialized)
 		{
@@ -655,17 +726,14 @@ gkrellm_sys_inet_init(void)
 /* ===================================================================== */
 /* Memory/Swap monitor interface */
 
-#include <osreldate.h>
-#include <kvm.h>
-#include <limits.h>
 #include <sys/conf.h>
 #if __FreeBSD_version < 400000
 #include <sys/rlist.h>
 #endif
 #include <sys/vmmeter.h>
-#include <sys/sysctl.h>
 #include <vm/vm_param.h>
 
+#if __FreeBSD_version < 410000
 static struct nlist nl_mem[] = {
 #define N_CNT		0
 	{ "_cnt" },
@@ -687,17 +755,20 @@ static struct nlist nl_mem[] = {
 #endif
 	{ "" }
 };
-
-extern	kvm_t	*kvmd;
-extern	char	errbuf[];
+#endif
 
 static int
-swapmode(guint64 *retavail, guint64 *retfree)
+swapmode(unsigned long long *retavail, unsigned long long *retfree)
 	{
 	guint64 used, avail;
 #if  __FreeBSD_version >= 400000
 	static int psize = -1;
 	struct kvm_swap kvmswap;
+#if __FreeBSD_version >= 500000
+	struct xswdev xsw;
+	size_t mibsize, size;
+	int mib[16], n;
+#endif
 #else
 	char *header;
 	int hlen, nswap, nswdev, dmmax;
@@ -734,21 +805,37 @@ swapmode(guint64 *retavail, guint64 *ret
 		}
 	warning--;		/* decrease counter, see end of function */
 
+#if __FreeBSD_version >= 400000
+#if __FreeBSD_version >= 500000
+	mibsize = sizeof mib / sizeof mib[0];
+	if (gk_sysctlnametomib("vm.swap_info", mib, &mibsize) == -1)
+		return(0);
+	kvmswap.ksw_total = 0;
+	kvmswap.ksw_used = 0;
+	for (n = 0; ; ++n)
+		{
+		mib[mibsize] = n;
+		size = sizeof xsw;
+		if (sysctl(mib, mibsize + 1, &xsw, &size, NULL, 0) == -1)
+			break;
+		kvmswap.ksw_total += xsw.xsw_nblks;
+		kvmswap.ksw_used += xsw.xsw_used;
+		}
+#else
 	if (kvmd == NULL)
 		return(0);
-#if  __FreeBSD_version >= 400000
 	if (kvm_getswapinfo(kvmd, &kvmswap, 1, 0) < 0)
-		{
-		fprintf(stderr, "kvm_getswapinfo failed\n");
 		return(0);
-		}
 
+#endif
 	if (psize < 0)
-	    psize = getpagesize();
+		psize = getpagesize();
 	*retavail = avail = (quad_t)kvmswap.ksw_total * psize;
 	used = (quad_t)kvmswap.ksw_used * psize;
 	*retfree = avail - used;
 #else
+	if (kvmd == NULL)
+		return(0);
 	if (kvm_read(kvmd, nl_mem[VM_NSWAP].n_value,
 		     &nswap, sizeof(nswap)) != sizeof(nswap))
 		return(0);
@@ -898,7 +985,7 @@ get_bufspace(guint64 *bufspacep)
 		}
 
 	if (sysctl(oid_bufspace, oid_bufspace_len,
-		   &bufspace, &bufspace_len, 0, 0) < 0)
+		   &bufspace, &bufspace_len, NULL, 0) < 0)
 		return 0;
 #endif
 	*bufspacep = bufspace;
@@ -942,9 +1029,9 @@ static struct mibtab mibs[] = {
 #endif
 
 static guint64	swapin,
-		swapout,
-		swap_total,
-		swap_used;
+		swapout;
+static unsigned long long	swap_total,
+				swap_used;
 
 void
 gkrellm_sys_mem_read_data(void)
@@ -954,15 +1041,14 @@ gkrellm_sys_mem_read_data(void)
 	static gint	swappgsin = -1;
 	static gint	swappgsout = -1;
 	gint		dpagein, dpageout;
-	struct vmmeter	sum;
-	guint64		total, used, x_used, free, shared, buffers, cached;
+	guint64		total, used, x_used, free, shared, buffers = 0, cached;
 	struct vmtotal	vmt;
 	size_t		length_vmt = sizeof(vmt);
 	static int	oid_vmt[] = { CTL_VM, VM_TOTAL };
 #if __FreeBSD_version >= 410000
 	gint		i;
-	FILE		*f;
-	gchar		buf[160];
+#else
+	struct vmmeter	sum;
 #endif
 
 #if 0
@@ -981,60 +1067,49 @@ gkrellm_sys_mem_read_data(void)
 		}
 
 	shared = 0;
-	if (kvmd == NULL)
-		{
 #if __FreeBSD_version >= 410000
-		if (!first_time_done)
-			{
-			for (i = 0; mibs[i].name; ++i)
-				{
-				mibs[i].oid_len = sizeof(mibs[i].oid);
-				if (gk_sysctlnametomib(mibs[i].name,
-						       mibs[i].oid,
-						       &mibs[i].oid_len) < 0)
-				 	return;
-				mibs[i].value_len = sizeof(mibs[i].value);
-				}
-			++first_time_done;
-			}
+	if (!first_time_done)
+		{
 		for (i = 0; mibs[i].name; ++i)
-			if (sysctl(mibs[i].oid, mibs[i].oid_len,
-				   &mibs[i].value,
-				   &mibs[i].value_len, 0, 0) < 0)
-				return;
-		total = (mibs[MIB_V_PAGE_COUNT].value -
-			     mibs[MIB_V_WIRE_COUNT].value) << pshift;
-		x_used = (mibs[MIB_V_ACTIVE_COUNT].value +
-			      mibs[MIB_V_INACTIVE_COUNT].value) << pshift;
-		free = mibs[MIB_V_FREE_COUNT].value << pshift;
-		if (sysctl(oid_vmt, 2, &vmt, &length_vmt, NULL, 0) == 0)
-			shared = vmt.t_rmshr << pshift;
-		get_bufspace(&buffers);
-		cached = mibs[MIB_V_CACHE_COUNT].value << pshift;
-		used = x_used - buffers - cached;
-		gkrellm_mem_assign_data(total, used, free, shared, buffers, cached);
-
-		swapin = mibs[MIB_V_SWAPPGSIN].value;
-		swapout = mibs[MIB_V_SWAPPGSOUT].value;
-
-		/* Try linprocfs for swap info */
-		if ((f = fopen(PROC_MEMINFO_FILE, "r")) == NULL)
-			return;
-		/* total: used: free: shared: buffers: cached: */
-		while ((fgets(buf, sizeof(buf), f)) != NULL)
 			{
-			if (strncmp(buf, "Swap:", 5) == 0)
-				{
-				sscanf(buf, "Swap: %llu %llu",
-				       &swap_total, &swap_used);
-				break;
-				}
+			mibs[i].oid_len = sizeof(mibs[i].oid);
+			if (gk_sysctlnametomib(mibs[i].name, mibs[i].oid,
+					       &mibs[i].oid_len) < 0)
+				return;
+			mibs[i].value_len = sizeof(mibs[i].value);
 			}
-		fclose(f);
-#endif
-		return;
 		}
+	for (i = 0; mibs[i].name; ++i)
+		if (sysctl(mibs[i].oid, mibs[i].oid_len, &mibs[i].value,
+			   &mibs[i].value_len, NULL, 0) < 0)
+			return;
+	total = (mibs[MIB_V_PAGE_COUNT].value -
+		     mibs[MIB_V_WIRE_COUNT].value) << pshift;
+	x_used = (mibs[MIB_V_ACTIVE_COUNT].value +
+		      mibs[MIB_V_INACTIVE_COUNT].value) << pshift;
+	free = mibs[MIB_V_FREE_COUNT].value << pshift;
+	if (sysctl(oid_vmt, 2, &vmt, &length_vmt, NULL, 0) == 0)
+		shared = vmt.t_rmshr << pshift;
+	get_bufspace(&buffers);
+	cached = mibs[MIB_V_CACHE_COUNT].value << pshift;
+	used = x_used - buffers - cached;
+	gkrellm_mem_assign_data(total, used, free, shared, buffers, cached);
 
+	if (swappgsin < 0)
+		{
+		dpagein = 0;
+		dpageout = 0;
+		}
+	else
+		{
+		dpagein = (mibs[MIB_V_SWAPPGSIN].value - swappgsin) << pshift;
+		dpageout = (mibs[MIB_V_SWAPPGSOUT].value - swappgsout) << pshift;
+		}
+	swappgsin = mibs[MIB_V_SWAPPGSIN].value;
+	swappgsout = mibs[MIB_V_SWAPPGSOUT].value;
+#else
+	if (kvmd == NULL)
+		return;
 	if (nl_mem[0].n_type == 0)
 		if (kvm_nlist(kvmd, nl_mem) < 0 || nl_mem[0].n_type == 0)
 			return;
@@ -1051,6 +1126,7 @@ gkrellm_sys_mem_read_data(void)
 	cached = sum.v_cache_count << pshift;
 	used = x_used - buffers - cached;
 	gkrellm_mem_assign_data(total, used, free, shared, buffers, cached);
+
 	if (swappgsin < 0)
 		{
 		dpagein = 0;
@@ -1058,11 +1134,12 @@ gkrellm_sys_mem_read_data(void)
 		}
 	else
 		{
-		dpagein = (sum.v_swappgsin - swappgsin) << (pshift - 10);
-		dpageout = (sum.v_swappgsout - swappgsout) << (pshift - 10);
+		dpagein = (sum.v_swappgsin - swappgsin) << pshift;
+		dpageout = (sum.v_swappgsout - swappgsout) << pshift;
 		}
 	swappgsin = sum.v_swappgsin;
 	swappgsout = sum.v_swappgsout;
+#endif
 
 	if (dpagein > 0 || dpageout > 0 || first_time_done == 0)
 		{
@@ -1090,8 +1167,8 @@ gkrellm_sys_mem_init(void)
 /* ===================================================================== */
 /* Battery monitor interface */
 
+#if defined(__i386__) || defined(__amd64__)
 #if defined(__i386__)
-#include <osreldate.h>
 #include <machine/apm_bios.h>
 #define	APMDEV		"/dev/apm"
 
@@ -1099,6 +1176,7 @@ gkrellm_sys_mem_init(void)
 #define	L_ON_LINE		1
 #define	L_CHARGING		3
 #define L_UNKNOWN		0xFF
+#endif
 
 /* following two definitions are taken from sys/dev/acpica/acpiio.h */
 #define ACPI_BATT_STAT_CHARGING		0x0002
@@ -1125,16 +1203,18 @@ gkrellm_sys_battery_read_data(void)
 	size_t		size;
 	int		acpi_info[4];
 	int		i;
+#if defined(__i386__)
 	int		f, r;
 	struct apm_info	info;
+	gint		batt_num = 0;
+#endif
 	gboolean	available, on_line, charging;
 	gint		percent, time_left;
-	gint		batt_num = 0;
 
 	if (!first_time_done)
 		{
 		first_time_done = TRUE;
-#ifdef ACPI_SUPPORTS_MULTIPLE_BATTERIES
+#if defined(ACPI_SUPPORTS_MULTIPLE_BATTERIES) || defined(__amd64__)
 		/*
 		 * XXX: Disable getting battery information via ACPI
 		 * to support multiple batteries via APM sim until
@@ -1174,6 +1254,7 @@ gkrellm_sys_battery_read_data(void)
 			return;
 		}
 
+#if defined(__i386__)
 	if ((f = open(APMDEV, O_RDONLY)) == -1)
 		return;
 	if ((r = ioctl(f, APMIO_GETINFO, &info)) == -1) {
@@ -1231,6 +1312,7 @@ gkrellm_sys_battery_read_data(void)
 #endif
 
 	close(f);
+#endif
 	}
 
 gboolean
@@ -1258,7 +1340,7 @@ gkrellm_sys_battery_init(void)
 /* ===================================================================== */
 /* Sensor monitor interface */
 
-#if defined(__i386__)
+#if defined(__i386__) || defined(__amd64__)
 
 typedef struct
 	{
@@ -1286,7 +1368,6 @@ static VoltDefault	voltdefault0[] =
 	};
 
 #include <dirent.h>
-#include <osreldate.h>
 #include <machine/cpufunc.h>
 #if __FreeBSD_version >= 500042
 #include <dev/smbus/smb.h>
@@ -1298,6 +1379,8 @@ static VoltDefault	voltdefault0[] =
 #define INTERFACE_IO		0
 #define INTERFACE_SMB		1
 #define INTERFACE_ACPI		2
+#define INTERFACE_CORETEMP	3		/* Already in Celsius */
+#define INTERFACE_AMDTEMP	4
 
 /* Addresses to use for /dev/io */
 #define WBIO1			0x295
@@ -1331,7 +1414,7 @@ get_data(int iodev, u_char command, int 
 		struct smbcmd cmd;
 
 		bzero(&cmd, sizeof(cmd));
-		cmd.data.byte_ptr = &byte;
+		cmd.data.byte_ptr = (char *)&byte;
 		cmd.slave         = 0x5a;
 		cmd.cmd           = command;
 		if (ioctl(iodev, SMB_READB, (caddr_t)&cmd) == -1)
@@ -1357,6 +1440,8 @@ gkrellm_sys_sensors_get_temperature(gcha
 
 	{
 	u_char byte;
+	int value;
+	size_t size;
 
 	if (interface == MBMON_INTERFACE)
 		{
@@ -1364,17 +1449,18 @@ gkrellm_sys_sensors_get_temperature(gcha
 		return gkrellm_sys_sensors_mbmon_get_value(path, temp);
 		}
 
-	if (interface == INTERFACE_ACPI)
+	if (interface == INTERFACE_ACPI || interface == INTERFACE_CORETEMP ||
+	    interface == INTERFACE_AMDTEMP)
 		{
-		int value;
-		size_t size = sizeof(value);
-
+		size = sizeof(value);
 		if (sysctlbyname(path, &value, &size, NULL, 0) < 0)
 			return FALSE;
 		if (temp)
-			*temp = (gfloat) TZ_KELVTOC(value);
+			*temp = (interface == INTERFACE_CORETEMP) ?
+				(gfloat) value : (gfloat) TZ_KELVTOC(value);
 		return TRUE;
 		}
+
 	if (get_data(iodev, LM78_TEMP, interface, &byte))
 		{
 		if (temp)
@@ -1444,10 +1530,10 @@ static GList	*freebsd_sensor_list;
 gboolean
 gkrellm_sys_sensors_init(void)
 	{
-	gchar		mib_name[256], label[8];
+	gchar		mib_name[256], label[8], buf[BUFSIZ], *fmt;
 	gint		interface, id;
-	int		oid_acpi_temp[CTL_MAXNAME + 2];
-	size_t		oid_acpi_temp_len = sizeof(oid_acpi_temp);
+	int		oid[CTL_MAXNAME + 2];
+	size_t		oid_len, len;
 	GList		*list;
 	struct freebsd_sensor *sensor;
 
@@ -1455,12 +1541,13 @@ gkrellm_sys_sensors_init(void)
 	*/
 	gkrellm_sys_sensors_mbmon_check(TRUE);
 
-	for (id = 0;;)
-	{
+	/* ACPI Thermal */
+	for (id = 0;; id++)
+		{
 		snprintf(mib_name, sizeof(mib_name),
 			 "hw.acpi.thermal.tz%d.temperature", id);
-		if (gk_sysctlnametomib(mib_name, oid_acpi_temp,
-				       &oid_acpi_temp_len) < 0)
+		oid_len = sizeof(oid);
+		if (gk_sysctlnametomib(mib_name, oid, &oid_len) < 0)
 			break;
 		interface = INTERFACE_ACPI;
 		if (!gkrellm_sys_sensors_get_temperature(mib_name, 0, 0,
@@ -1470,7 +1557,33 @@ gkrellm_sys_sensors_init(void)
 		gkrellm_sensors_add_sensor(SENSOR_TEMPERATURE, NULL,
 					   mib_name, 0, 0,
 					   interface, 1.0, 0.0, NULL, label);
-	}
+		}
+
+	/* Coretemp and Amdtemp */
+	for (id = 0;; id++)
+		{
+		snprintf(mib_name, sizeof(mib_name),
+			 "dev.cpu.%d.temperature", id);
+		oid_len = sizeof(oid) - sizeof(int) * 2;
+		if (gk_sysctlnametomib(mib_name, oid + 2, &oid_len) < 0)
+			break;
+		oid[0] = 0;
+		oid[1] = 4;
+		len = sizeof(buf);
+		if (sysctl(oid, oid_len + 2, buf, &len, 0, 0) < 0)
+			break;
+		fmt = (gchar *)(buf + sizeof(u_int));
+		interface = (fmt[1] == 'K') ?
+			INTERFACE_AMDTEMP : INTERFACE_CORETEMP;
+		if (!gkrellm_sys_sensors_get_temperature(mib_name, 0, 0,
+							 interface, NULL))
+			continue;
+		snprintf(label, sizeof(label), "cpu%d", id);
+		gkrellm_sensors_add_sensor(SENSOR_TEMPERATURE, NULL,
+					   mib_name, 0, 0,
+					   interface, 1.0, 0.0, NULL, label);
+		}
+
 
 	if (freebsd_sensor_list)
 		{
@@ -1504,13 +1617,7 @@ sensors_add_sensor(gint type, gchar *id_
 	sensor->factor = factor;
 	sensor->offset = offset;
 	sensor->default_label = default_label ? g_strdup(default_label) : NULL;
-	if (g_list_append(freebsd_sensor_list, sensor) == NULL) {
-		g_free(sensor->id_name);
-		if (sensor->default_label)
-			g_free(sensor->default_label);
-		g_free(sensor);
-		return FALSE;
-	}
+	freebsd_sensor_list = g_list_append(freebsd_sensor_list, sensor);
 	return TRUE;
 }
 
