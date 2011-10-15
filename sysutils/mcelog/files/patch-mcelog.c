--- ./mcelog.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./mcelog.c	2011-10-14 22:37:22.000000000 -0400
@@ -20,8 +20,21 @@
 #define _GNU_SOURCE 1
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
+#ifdef __Linux__
 #include <asm/types.h>
 #include <asm/ioctls.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <machine/cpufunc.h>
+#include <machine/cputypes.h>
+#include <machine/specialreg.h>
+#include <err.h>
+#include <kvm.h>
+#include <limits.h>
+#endif
+#undef CPU_P4
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -57,9 +70,25 @@
 #include "yellow.h"
 #include "page.h"
 
+struct mca_record {
+        uint64_t        mr_status;
+        uint64_t        mr_addr;
+        uint64_t        mr_misc;
+        uint64_t        mr_tsc;
+        int             mr_apic_id;
+        int             mr_bank;
+        uint64_t        mr_mcg_cap;
+        uint64_t        mr_mcg_status;
+        int             mr_cpu_id;
+        int             mr_cpu_vendor_id;
+        int             mr_cpu;
+};
+
 enum cputype cputype = CPU_GENERIC;	
 
+#ifdef __Linux__
 char *logfn = LOG_DEV_FILENAME; 
+#endif
 
 int ignore_nodev;
 int filter_bogus = 1;
@@ -70,12 +99,18 @@
 int dump_raw_ascii;
 int daemon_mode;
 static char *inputfile;
+#ifdef __Linux__
 char *processor_flags;
+#endif
 static int foreground;
 int filter_memory_errors;
 static struct config_cred runcred = { .uid = -1U, .gid = -1U };
 static int numerrors;
 static char *pidfile;
+#ifdef __FreeBSD__
+static char *execfile;
+static char *corefile;
+#endif
 
 static void check_cpu(void);
 
@@ -388,6 +423,7 @@
 	Wprintf("\n");
 }
 
+#ifdef __Linux__
 void check_cpu(void)
 { 
 	enum { 
@@ -455,7 +491,44 @@
 	} else
 		Eprintf("warning: Cannot open /proc/cpuinfo\n");
 } 
+#endif
+
+#ifdef __FreeBSD__
+void check_cpu(void)
+{
+	char vendor[20];
+	u_int regs[4];
+	u_int cpu_id;
+	int family, model;
+	static int checked;
+
+	if (checked)
+		return;
+	checked = 1;
+
+	do_cpuid(0, regs);
+	((u_int *)vendor)[0] = regs[1];
+	((u_int *)vendor)[1] = regs[3];
+	((u_int *)vendor)[2] = regs[2];
+	vendor[12] = 0;
+
+	do_cpuid(1, regs);
+	cpu_id = regs[0];
+	family = CPUID_TO_FAMILY(cpu_id);
+	model = CPUID_TO_MODEL(cpu_id);
 
+	if (cpu_forced) 
+		;
+	else if (!strcmp(vendor,"AuthenticAMD") && 
+	    (family == 15 || family == 16 || family == 17))
+		cputype = CPU_K8;
+	else if (!strcmp(vendor,"GenuineIntel"))
+		cputype = select_intel_cputype(family, model);
+	/* Add checks for other CPUs here */	
+}
+#endif
+
+#ifdef __Linux__
 static char *skipspace(char *s)
 {
 	while (isspace(*s))
@@ -479,6 +552,7 @@
 	}
 	return skipspace(s);
 }
+#endif
 
 static void dump_mce_final(struct mce *m, char *symbol, int missing, int recordlen, 
 			   int dseen)
@@ -501,6 +575,7 @@
 	if (recordlen < endof_field(struct mce, f)) \
 		recordlen = endof_field(struct mce, f)
 
+#ifdef __Linux__
 /* Decode ASCII input for fatal messages */
 static void decodefatal(FILE *inf)
 {
@@ -646,6 +721,227 @@
 	if (data)
 		dump_mce_final(&m, symbol, missing, recordlen, disclaimer_seen);
 }
+#endif
+
+#ifdef __FreeBSD__
+/*
+ * Table used to map cpuid vendor strings and FreeBSD CPU vendor IDs
+ * to Linux cpuvendor values.
+ */
+static struct {
+	char *name;
+	int vendor_id;
+	u_char cpuvendor;
+} vendor_ids[] = {
+	{ "GenuineIntel", CPU_VENDOR_INTEL, 0 },
+	{ "AuthenticAMD", CPU_VENDOR_AMD, 2 },
+	{ "CentaurHauls", CPU_VENDOR_CENTAUR, 5 },
+#ifdef __i386__
+	{ "CyrixInstead", CPU_VENDOR_CYRIX, 1 },
+	{ "UMC UMC UMC ", CPU_VENDOR_UMC, 3 },
+	{ "GenuineTMx86", CPU_VENDOR_TRANSMETA, 7 },
+	{ "Geode by NSC", CPU_VENDOR_NSC, 8 },
+#endif
+};
+
+static int find_cpu_vendor(const char *vendor)
+{
+	u_int i;
+
+	for (i = 0; i < sizeof(vendor_ids) / sizeof(vendor_ids[0]); i++)
+		if (strcmp(vendor, vendor_ids[i].name) == 0)
+			return (vendor_ids[i].cpuvendor);
+	return (0xff);
+}
+
+static int find_cpu_vendor_id(const char *vendor)
+{
+	u_int i;
+
+	for (i = 0; i < sizeof(vendor_ids) / sizeof(vendor_ids[0]); i++)
+		if (strcmp(vendor, vendor_ids[i].name) == 0)
+			return (vendor_ids[i].vendor_id);
+	return (0);
+}
+
+static int map_cpu_vendor(int vendor_id)
+{
+	u_int i;
+
+	for (i = 0; i < sizeof(vendor_ids) / sizeof(vendor_ids[0]); i++)
+		if (vendor_ids[i].vendor_id == vendor_id)
+			return (vendor_ids[i].cpuvendor);
+	return (0xff);
+}
+
+/* Convert FreeBSD's struct mca_record into a struct mce. */
+static void convert_mca(struct mca_record *mr, struct mce *mce, int live,
+    size_t len)
+{
+	memset(mce, 0, sizeof(*mce));
+	mce->status = mr->mr_status;
+	mce->misc = mr->mr_misc;
+	mce->addr = mr->mr_addr;
+	mce->mcgstatus = mr->mr_mcg_status;
+	mce->tsc = mr->mr_tsc;
+	mce->cpuvendor = map_cpu_vendor(mr->mr_cpu_vendor_id);
+	mce->cpuid = mr->mr_cpu_id;
+	mce->bank = mr->mr_bank;
+	mce->finished = 1;
+	mce->extcpu = mr->mr_cpu;
+	mce->apicid = mr->mr_apic_id;
+	mce->mcgcap = mr->mr_mcg_cap;
+
+	/*
+	 * For older live records (from sysctl), fill in some fields
+	 * using registers from the current CPU.
+	 */
+	if (len < offsetof(struct mca_record, mr_cpu_id) && live) {
+		char vendor[20];
+		u_int regs[4];
+
+		do_cpuid(0, regs);
+		((u_int *)vendor)[0] = regs[1];
+		((u_int *)vendor)[1] = regs[3];
+		((u_int *)vendor)[2] = regs[2];
+		vendor[12] = 0;
+		mce->cpuvendor = find_cpu_vendor(vendor);
+
+		do_cpuid(1, regs);
+		mce->cpuid = regs[0];
+	}
+}
+
+/* Decode ASCII input for fatal messages */
+static void decodefatal(FILE *inf)
+{
+	struct mca_record mr;
+	struct mce m;
+	long long val, val2;
+	char *cp, line[100], *s, symbol[1];
+	const char *fmt;
+	int cpu, data, old, missing;
+	enum rows {
+		BANK = 0x1,
+		MCG = 0x2,
+		VENDOR = 0x4,
+		CPU = 0x8,
+		ADDR = 0x10,
+		MISC = 0x20,
+	};
+
+	symbol[0] = '\0';
+	data = 0;
+	missing = 0;
+	old = 0;
+	memset(&mr, 0, sizeof(mr));
+	while ((s = fgets(line, sizeof(line), inf)) != NULL) {
+		s = strstr(s, "MCA: ");
+		if (s == NULL)
+			continue;
+		s += strlen("MCA: ");
+
+		if (strncmp(s, "bank", 4) == 0 || strncmp(s, "Bank", 4) == 0) {
+			/* Start of a new record, dump the previous one. */
+			if (data != 0) {
+				/* Require some minimum data. */
+				if (data & BANK) {
+					if (mr.mr_status & MC_STATUS_ADDRV &&
+					    !(data & ADDR))
+						missing = 1;
+					if (mr.mr_status & MC_STATUS_MISCV &&
+					    !(data & MISC))
+						missing = 1;
+					convert_mca(&mr, &m, 0, sizeof(mr));
+					mce_cpuid(&m);
+					dump_mce_final(&m, symbol, missing,
+					    sizeof(struct mce), 0);
+				}
+				data = 0;
+				missing = 0;
+				memset(&mr, 0, sizeof(mr));
+			}
+
+			if (s[0] == 'b') {
+				old = 1;
+				fmt = "bank %d, status 0x%llx";
+			} else {
+				old = 0;
+				fmt = "Bank %d, Status 0x%llx";
+			}
+			if (sscanf(s, fmt, &mr.mr_bank, &val) != 2)
+				missing = 1;
+			else {
+				data |= BANK;
+				mr.mr_status = val;
+			}
+		}
+		if (strncmp(s, "Global", 6) == 0) {
+			if (sscanf(s, "Global Cap 0x%llx, Status 0x%llx", &val,
+			    &val2) != 2)
+				missing = 1;
+			else {
+				data |= MCG;
+				mr.mr_mcg_cap = val;
+				mr.mr_mcg_status = val2;
+			}
+		}
+		if (strncmp(s, "Vendor \"", 8) == 0) {
+			s += 8;
+			cp = index(s, '"');
+			if (cp != NULL) {
+				*cp = '\0';
+				mr.mr_cpu_vendor_id = find_cpu_vendor_id(s);
+				s = cp + 1;
+				if (sscanf(s, ", ID 0x%x, APIC ID %d",
+				    &mr.mr_cpu_id, &mr.mr_apic_id) != 2)
+					missing = 1;
+				else
+					data |= VENDOR;
+			} else
+				missing = 1;
+		}
+		if (strncmp(s, "CPU", 3) == 0) {
+			if (sscanf(s, "CPU %d ", &cpu) != 1)
+				missing = 1;
+			else {
+				data |= CPU;
+				if (old)
+					mr.mr_apic_id = cpu;
+				else
+					mr.mr_cpu = cpu;
+			}
+		}
+		if (strncmp(s, "Address", 7) == 0) {
+			if (sscanf(s, "Address 0x%llx", &val) != 1)
+				missing = 1;
+			else {
+				data |= ADDR;
+				mr.mr_addr = val;
+			}
+		}
+		if (strncmp(s, "Misc", 4) == 0) {
+			if (sscanf(s, "Misc 0x%llx", &val) != 1)
+				missing = 1;
+			else {
+				data |= MISC;
+				mr.mr_misc = val;
+			}
+		}
+	}
+
+	/* Dump the last record. */
+	if (data & BANK) {
+		if (mr.mr_status & MC_STATUS_ADDRV && !(data & ADDR))
+			missing = 1;
+		if (mr.mr_status & MC_STATUS_MISCV && !(data & MISC))
+			missing = 1;
+		convert_mca(&mr, &m, 0, sizeof(mr));
+		mce_cpuid(&m);
+		dump_mce_final(&m, symbol, missing, sizeof(struct mce), 0);
+	}
+}
+#endif
 
 static void remove_pidfile(void)
 {
@@ -686,6 +982,10 @@
 "  mcelog [options] --ascii < log\n"
 "  mcelog [options] --ascii --file log\n"
 "Decode machine check ASCII output from kernel logs\n"
+#ifdef __FreeBSD__
+"  mcelog [options] -M vmcore -N kernel\n"
+"Decode machine check error records from kernel crashdump.\n"
+#endif
 "Options:\n"  
 "--cpu CPU           Set CPU type CPU to decode (see below for valid types)\n"
 "--cpumhz MHZ        Set CPU Mhz to decode time (output unreliable, not needed on new kernels)\n"
@@ -866,6 +1166,14 @@
 	case O_CONFIG_FILE:
 		/* parsed in config.c */
 		break;
+#ifdef __FreeBSD__
+	case 'M':
+		corefile = strdup(optarg);
+		break;
+	case 'N':
+		execfile = strdup(optarg);
+		break;
+#endif
 	case 0:
 		break;
 	default:
@@ -900,8 +1208,10 @@
 
 static void general_setup(void)
 {
+#ifdef __Linux__
 	trigger_setup();
 	yellow_setup();
+#endif
 	config_cred("global", "run-credentials", &runcred);
 	if (config_bool("global", "filter-memory-errors") == 1)
 		filter_memory_errors = 1;
@@ -924,6 +1234,7 @@
 	}
 }
 
+#ifdef __Linux__
 static void process(int fd, unsigned recordlen, unsigned loglen, char *buf)
 {	
 	int i; 
@@ -964,6 +1275,173 @@
 	if (finish)
 		exit(0);
 }
+#endif
+
+#ifdef __FreeBSD__
+#ifdef LOCAL_HACK
+struct mca_record_old {
+	uint64_t	mr_status;
+	uint64_t	mr_addr;
+	uint64_t	mr_misc;
+	uint64_t	mr_tsc;
+	int		mr_apic_id;
+	int		mr_bank;
+};
+#endif
+
+struct mca_record_internal {
+	struct mca_record rec;
+	int		logged;
+	STAILQ_ENTRY(mca_internal) link;
+};
+
+#ifdef LOCAL_HACK
+struct mca_record_internal_old {
+	struct mca_record_old rec;
+	int		logged;
+	STAILQ_ENTRY(mca_internal) link;
+};
+#endif
+
+static struct nlist nl[] = {
+#define	X_MCA_RECORDS		0
+	{ .n_name = "_mca_records" },
+#ifdef LOCAL_HACK
+#define	X_SNAPDATE		1
+	{ .n_name = "_snapdate" },
+#endif
+	{ .n_name = NULL },
+};
+
+static int
+kread(kvm_t *kvm, void *kvm_pointer, void *buf, size_t size, size_t offset)
+{
+	ssize_t ret;
+
+	ret = kvm_read(kvm, (unsigned long)kvm_pointer + offset, buf, size);
+	if (ret < 0 || (size_t)ret != size)
+		return (-1);
+	return (0);
+}
+
+static int
+kread_symbol(kvm_t *kvm, int index, void *buf, size_t size)
+{
+	ssize_t ret;
+
+	ret = kvm_read(kvm, nl[index].n_value, buf, size);
+	if (ret < 0 || (size_t)ret != size)
+		return (-1);
+	return (0);
+}
+
+static void process_kvm(const char *execfile, const char *corefile)
+{
+	struct mca_record mr, *mrp;
+	struct mce mce;
+	char errbuf[_POSIX2_LINE_MAX];
+	kvm_t *kvm;
+	size_t record_size, link_offset;
+	int i;
+#ifdef LOCAL_HACK
+	int snapdate;
+#endif
+
+	kvm = kvm_openfiles(execfile, corefile, NULL, O_RDONLY, errbuf);
+	if (kvm == NULL)
+		errx(1, "kvm_openfiles: %s", errbuf);
+	if (kvm_nlist(kvm, nl) != 0)
+		errx(1, "kvm_nlist: %s", kvm_geterr(kvm));
+
+#ifdef LOCAL_HACK
+	if (kread_symbol(kvm, X_SNAPDATE, &snapdate, sizeof(snapdate)) < 0)
+		errx(1, "kvm_read(snapdate) failed");
+#endif
+	/* stqh_first is the first pointer at this address. */
+	if (kread_symbol(kvm, X_MCA_RECORDS, &mrp, sizeof(mrp)) < 0)
+		errx(1, "kvm_read(mca_records) failed");
+#ifdef LOCAL_HACK
+	if (snapdate >= 20100329) {
+#endif
+		record_size = sizeof(struct mca_record);
+		link_offset = __offsetof(struct mca_record_internal,
+		    link.stqe_next);
+#ifdef LOCAL_HACK
+	} else {
+		record_size = sizeof(struct mca_record_old);
+		link_offset = __offsetof(struct mca_record_internal_old,
+		    link.stqe_next);
+	}
+#endif
+
+	for (i = 0; mrp != NULL; i++) {
+		memset(&mr, 0, sizeof(mr));
+		if (kread(kvm, mrp, &mr, record_size, 0) < 0)
+			break;
+		if (kread(kvm, mrp, &mrp, sizeof(mrp), link_offset) < 0)
+			mrp = NULL;
+
+		convert_mca(&mr, &mce, 1, record_size);
+		mce_prepare(&mce);
+		if (!mce_filter(&mce, sizeof(struct mce))) 
+			continue;
+		if (!dump_raw_ascii) {
+			disclaimer();
+			Wprintf("MCE %d\n", i);
+			dump_mce(&mce, sizeof(struct mce));
+		} else
+			dump_mce_raw_ascii(&mce, sizeof(struct mce));
+		flushlog();
+	}
+
+	exit(0);
+}
+
+static void process_live(void)
+{
+	struct mca_record mr;
+	struct mce mce;
+	int mib[4];
+	size_t len;
+	int count, finish, i;
+
+	len = sizeof(count);
+	if (sysctlbyname("hw.mca.count", &count, &len, NULL, 0) < 0)
+		return;
+
+	len = 4;
+	if (sysctlnametomib("hw.mca.records", mib, &len) < 0)
+		return;
+
+	finish = 0;
+	for (i = 0; i < count; i++) {
+		mib[3] = i;
+		len = sizeof(mr);
+		memset(&mr, 0, sizeof(mr));
+		if (sysctl(mib, 4, &mr, &len, NULL, 0) < 0) {
+			warn("sysctl(hw.mca.records.%d)", i);
+			continue;
+		}
+
+		convert_mca(&mr, &mce, 1, len);
+		mce_prepare(&mce);
+		if (numerrors > 0 && --numerrors == 0)
+			finish = 1;
+		if (!mce_filter(&mce, sizeof(struct mce))) 
+			continue;
+		if (!dump_raw_ascii) {
+			disclaimer();
+			Wprintf("MCE %d\n", i);
+			dump_mce(&mce, sizeof(struct mce));
+		} else
+			dump_mce_raw_ascii(&mce, sizeof(struct mce));
+		flushlog();
+	}
+
+	if (finish)
+		exit(0);
+}
+#endif
 
 static void noargs(int ac, char **av)
 {
@@ -1022,22 +1500,30 @@
 	char *buf;
 };
 
+#ifdef __Linux__
 static void process_mcefd(struct pollfd *pfd, void *data)
 {
 	struct mcefd_data *d = (struct mcefd_data *)data;
 	assert((pfd->revents & POLLIN) != 0);
 	process(pfd->fd, d->recordlen, d->loglen, d->buf);
 }
+#endif
 
 int main(int ac, char **av) 
 { 
+#ifdef __Linux__
 	struct mcefd_data d = {};
-	int opt;
 	int fd;
+#endif
+	int opt;
 
 	parse_config(av);
 
-	while ((opt = getopt_long(ac, av, "", options, NULL)) != -1) { 
+#ifdef __FreeBSD__
+	while ((opt = getopt_long(ac, av, "M:N:", options, NULL)) != -1) {
+#else
+	while ((opt = getopt_long(ac, av, "", options, NULL)) != -1) {
+#endif
 		if (opt == '?') {
 			usage(); 
 		} else if (combined_modifier(opt) > 0) {
@@ -1057,13 +1543,21 @@
 		} else if (opt == 0)
 			break;		    
 	} 
+#ifdef __Linux__
 	if (av[optind])
 		logfn = av[optind++];
+#endif
 	if (av[optind])
 		usage();
+#ifdef __FreeBSD__
+	if ((corefile != NULL) ^ (execfile != NULL) ||
+	    (corefile != NULL && daemon_mode))
+		usage();
+#endif
 	checkdmi();
 	general_setup();
 		
+#ifdef __Linux__
 	fd = open(logfn, O_RDONLY); 
 	if (fd < 0) {
 		if (ignore_nodev) 
@@ -1078,24 +1572,39 @@
 		err("MCE_GET_LOG_LEN");
 
 	d.buf = xalloc(d.recordlen * d.loglen); 
+#endif
 	if (daemon_mode) {
 		check_cpu();
 		prefill_memdb();
 		if (!do_dmi)
 			closedmi();
 		server_setup();
+#ifdef __Linux__
 		page_setup();
+#endif
 		drop_cred();
+#ifdef __Linux__
 		register_pollcb(fd, POLLIN, process_mcefd, &d);
+#endif
 		if (!foreground && daemon(0, need_stdout()) < 0)
 			err("daemon");
 		if (pidfile)
 			write_pidfile();
 		eventloop();
 	} else {
+#ifdef __Linux__
 		process(fd, d.recordlen, d.loglen, d.buf);
+#endif
+#ifdef __FreeBSD__
+		if (corefile != NULL)
+			process_kvm(execfile, corefile);
+		else
+			process_live();
+#endif
 	}
+#ifdef __Linux__
 	trigger_wait();
+#endif
 		
 	exit(0); 
 } 
