--- lsmsr.c.orig	2011-04-05 15:54:04.000000000 -0700
+++ lsmsr.c	2011-09-15 16:44:15.000000000 -0700
@@ -31,6 +31,18 @@
 #include "AMD/fam11h.h"
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
@@ -116,6 +128,33 @@
 	fprintf(stdout, "%s version %s\n", g.prog, VERSION);
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
@@ -141,11 +180,17 @@
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
@@ -161,7 +206,7 @@
 
 static int _show_msr(struct reg_spec *reg)
 {
-	unsigned long long val;
+	unsigned long long val = 0;
 	if (!g.list)
 		if (get_msr_val(reg->address, &val))
 			return 1;
