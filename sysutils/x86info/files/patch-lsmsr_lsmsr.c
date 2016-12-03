--- lsmsr/lsmsr.c.orig	2016-10-12 19:04:55 UTC
+++ lsmsr/lsmsr.c
@@ -34,6 +34,18 @@
 #include "AMD_fam15h.h"
 #include "generic_msr.h"
 
+#if defined(__FreeBSD__)
+# include <sys/param.h>
+# include <sys/ioctl.h>
+# if __FreeBSD_version < 701102
+#  define CPUDEV "/dev/cpu%d"
+#  include <cpu.h>
+# else
+#  define CPUDEV "/dev/cpuctl%d"
+#  include <sys/cpuctl.h>
+# endif
+#endif
+
 /* Todos:
  * - add (list and eventually write) support for write-only MSR
  * - add decoding support for bit fields
@@ -119,13 +131,40 @@ static void version(void)
 	fprintf(stdout, "%s version %s\n", g.prog, LSMSR_VERSION);
 }
 
+#if defined(__FreeBSD__)
+
+static int get_msr_val(unsigned int msr, unsigned long long *val)
+{
+#if __FreeBSD_version < 701102
+	cpu_msr_args_t args;
+#else   
+	cpuctl_msr_args_t args;
+#endif
+
+	args.msr = msr;
+#if __FreeBSD_version < 701102
+	if (ioctl(g.fd, CPU_RDMSR, &args) != 0) {
+#else
+	if (ioctl(g.fd, CPUCTL_RDMSR, &args) != 0) {
+#endif
+		fflush(stdout);
+		fprintf(stderr,
+			"could not read MSR 0x%8.8x (%s): %s\n",
+			msr, get_reg_name(msr, g.msr_table), strerror(errno));
+		return 0;
+	}
+	*val = args.data;
+
+	return 0;
+}
+#else /* !__FreeBSD__ */
 static int get_msr_val(unsigned int msr, unsigned long long *val)
 {
 	off64_t off;
 	int err;
 
 	*val = 0;
-	off = lseek64(g.fd, (off64_t) msr, SEEK_SET);
+	off = lseek(g.fd, (off64_t) msr, SEEK_SET);
 	if (off == (off_t) -1) {
 		perror("invalid MSR");
 		return 1;
@@ -144,11 +183,17 @@ static int get_msr_val(unsigned int msr,
 	return 0;
 }
 
+#endif
+
 static int open_dev(int cpu)
 {
 	char s[20];
 
+#ifdef __FreeBSD__
+	snprintf(s, sizeof(s), CPUDEV, cpu);
+#else
 	snprintf(s, sizeof(s), "/dev/cpu/%d/msr", cpu);
+#endif
 	g.fd = open(s, O_RDONLY);
 	if (g.fd < 0)
 		fprintf(stderr, "could not open device %s: %s\n", s,
@@ -317,6 +362,7 @@ static int set_msr_table(void)
 }
 
 struct reg_spec unknown_msr = {0, "unknown", "(at your own risk)", NULL, NULL};
+unsigned int nrCPUs = 1;
 
 #define OPT_MAX 32
 int main(int argc, char *argv[])
@@ -325,6 +371,10 @@ int main(int argc, char *argv[])
 	int i, li, ret;
 	struct reg_spec *reg;
 
+	nrCPUs = sysconf(_SC_NPROCESSORS_ONLN);
+	if (nrCPUs > 65535)
+		nrCPUs = 1;
+
 	ret = 1;
 	if((g.prog = rindex(argv[0], '/')))
 		++g.prog;
